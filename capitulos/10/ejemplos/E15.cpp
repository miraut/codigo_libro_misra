// CH10-E15. Integrador: rechazo completo de una operación de telemetría.
#include <array>
#include <charconv>
#include <cstddef>
#include <cstdint>
#include <string_view>
#include <system_error>
#include <variant>

namespace telemetria
{
struct Registro
{
    std::uint16_t canal{0U};
    std::uint32_t lectura{0U};
};

enum class ErrorEntrada : std::uint8_t
{
    formato_invalido,
    valor_fuera_de_rango
};

using ResultadoConversion = std::variant<std::uint32_t, ErrorEntrada>;

ResultadoConversion convertir_lectura(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return ErrorEntrada::formato_invalido;
    }

    std::uint32_t valor{0U};
    char const* const primero = texto.data();
    char const* const ultimo = primero + texto.size();
    auto const resultado = std::from_chars(primero, ultimo, valor);

    if (resultado.ec == std::errc::result_out_of_range)
    {
        return ErrorEntrada::valor_fuera_de_rango;
    }
    if ((resultado.ec != std::errc{}) || (resultado.ptr != ultimo))
    {
        return ErrorEntrada::formato_invalido;
    }
    return valor;
}

class ColaRegistros
{
public:
    bool insertar(Registro registro) noexcept
    {
        if (ocupados_ >= registros_.size())
        {
            return false;
        }
        registros_[ocupados_] = registro;
        ++ocupados_;
        return true;
    }

    std::size_t cantidad() const noexcept { return ocupados_; }
    Registro consultar(std::size_t posicion) const noexcept
    {
        return registros_[posicion]; // Precondición: posicion < cantidad().
    }

private:
    std::array<Registro, 4U> registros_{};
    std::size_t ocupados_{0U};
};

enum class EstadoRecepcion : std::uint8_t
{
    aceptada,
    formato_invalido,
    valor_fuera_de_rango,
    cola_llena
};

EstadoRecepcion recibir(ColaRegistros& cola, std::uint16_t canal,
                         std::string_view texto) noexcept
{
    auto const conversion = convertir_lectura(texto);
    auto const* const valor = std::get_if<std::uint32_t>(&conversion);

    if (valor == nullptr)
    {
        auto const* const error = std::get_if<ErrorEntrada>(&conversion);
        if ((error != nullptr) &&
            (*error == ErrorEntrada::valor_fuera_de_rango))
        {
            return EstadoRecepcion::valor_fuera_de_rango;
        }
        return EstadoRecepcion::formato_invalido;
    }

    if (!cola.insertar(Registro{canal, *valor}))
    {
        return EstadoRecepcion::cola_llena;
    }
    return EstadoRecepcion::aceptada;
}
}
