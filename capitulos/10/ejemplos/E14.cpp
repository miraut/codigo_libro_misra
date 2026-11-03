// CH10-E14. Un resultado que conserva la causa del fallo.
#include <charconv>
#include <cstdint>
#include <string_view>
#include <system_error>
#include <variant>

namespace ejemplo_resultado
{
struct Lectura
{
    std::uint32_t valor;
};

enum class ErrorInterpretacion : std::uint8_t
{
    formato_invalido,
    fuera_de_rango
};

using ResultadoInterpretacion = std::variant<Lectura, ErrorInterpretacion>;

ResultadoInterpretacion interpretar_lectura(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return ErrorInterpretacion::formato_invalido;
    }

    std::uint32_t numero{0U};
    char const* const inicio = texto.data();
    char const* const fin = inicio + texto.size();
    auto const conversion = std::from_chars(inicio, fin, numero);

    if (conversion.ec == std::errc::result_out_of_range)
    {
        return ErrorInterpretacion::fuera_de_rango;
    }
    if ((conversion.ec != std::errc{}) || (conversion.ptr != fin))
    {
        return ErrorInterpretacion::formato_invalido;
    }
    return Lectura{numero};
}
}
