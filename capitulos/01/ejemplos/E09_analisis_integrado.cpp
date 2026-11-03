// CH01-E09. Componente completo del caso; C++17.
#include <array>
#include <cstdint>

namespace adquisicion
{
using TramaPeriodo = std::array<std::uint8_t, 4>;
using LeerMarcaTemporal = std::uint32_t (*)() noexcept;

enum class EstadoLectura
{
    valida,
    sin_medida,
    trama_incorrecta,
    reloj_no_disponible
};

struct ResultadoLectura
{
    EstadoLectura estado;
    std::uint32_t frecuencia_hercios;
    std::uint32_t marca_temporal_ticks;
};

ResultadoLectura analizar_trama(TramaPeriodo const& trama,
                               LeerMarcaTemporal leer_marca) noexcept
{
    if ((trama[0] != 1U) || (trama[1] > 1U))
    {
        return {EstadoLectura::trama_incorrecta, 0U, 0U};
    }

    if (trama[1] == 0U)
    {
        return {EstadoLectura::sin_medida, 0U, 0U};
    }

    std::uint32_t const periodo_microsegundos{
        (static_cast<std::uint32_t>(trama[2]) << 8U) |
        static_cast<std::uint32_t>(trama[3])
    };

    if (periodo_microsegundos == 0U)
    {
        return {EstadoLectura::sin_medida, 0U, 0U};
    }

    if (leer_marca == nullptr)
    {
        return {EstadoLectura::reloj_no_disponible, 0U, 0U};
    }

    return {
        EstadoLectura::valida,
        1'000'000U / periodo_microsegundos,
        leer_marca()
    };
}
}
