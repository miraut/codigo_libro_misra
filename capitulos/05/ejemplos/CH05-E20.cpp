// CH05-E20. Parser transaccional de una trama fija en C++17.
#include <array>
#include <cstddef>
#include <cstdint>

namespace receptor_robusto {
using Trama = std::array<std::uint8_t, 8U>;

enum class Error : std::uint8_t {
    ninguno,
    marca,
    version,
    canal,
    indicadores,
    periodo,
    comprobacion
};

struct Muestra {
    std::uint8_t canal{0U};
    std::uint8_t indicadores{0U};
    std::uint16_t lectura{0U};
    std::uint8_t periodo{0U};
};

struct Resultado {
    Error error{Error::marca};
    Muestra muestra{};

    bool correcto() const noexcept { return error == Error::ninguno; }
};

Resultado decodificar(Trama const& trama) noexcept
{
    if (trama[0U] != 0xA5U) { return {Error::marca, {}}; }
    if (trama[1U] != 1U) { return {Error::version, {}}; }
    if (trama[2U] >= 4U) { return {Error::canal, {}}; }
    if ((static_cast<std::uint32_t>(trama[3U]) & 0xFCU) != 0U)
    {
        return {Error::indicadores, {}};
    }
    if (trama[6U] == 0U) { return {Error::periodo, {}}; }

    std::uint8_t comprobacion{0U};
    for (std::size_t indice{0U}; indice < 7U; ++indice)
    {
        comprobacion = static_cast<std::uint8_t>(
            static_cast<std::uint32_t>(comprobacion) ^
            static_cast<std::uint32_t>(trama[indice]));
    }
    if (comprobacion != trama[7U])
    {
        return {Error::comprobacion, {}};
    }

    std::uint16_t const lectura = static_cast<std::uint16_t>(
        (static_cast<std::uint32_t>(trama[5U]) << 8U) |
        static_cast<std::uint32_t>(trama[4U]));
    Muestra const candidata{trama[2U], trama[3U], lectura, trama[6U]};
    return {Error::ninguno, candidata};
}

class Controlador {
public:
    bool recibir(Trama const& trama) noexcept
    {
        Resultado const resultado = decodificar(trama);
        if (!resultado.correcto())
        {
            return false;
        }

        // Todas las comprobaciones han terminado; se publica la muestra.
        historial_[siguiente_] = resultado.muestra;
        ultimo_ = resultado.muestra;
        siguiente_ = (siguiente_ + 1U) % historial_.size();
        if (ocupacion_ < historial_.size()) { ++ocupacion_; }
        ++aceptadas_;
        return true;
    }

    Muestra const& ultima() const noexcept { return ultimo_; }
    std::uint32_t aceptadas() const noexcept { return aceptadas_; }
    std::size_t ocupacion() const noexcept { return ocupacion_; }
    std::size_t siguiente() const noexcept { return siguiente_; }

private:
    std::array<Muestra, 4U> historial_{};
    Muestra ultimo_{};
    std::size_t siguiente_{0U};
    std::size_t ocupacion_{0U};
    std::uint32_t aceptadas_{0U};
};
} // namespace receptor_robusto
