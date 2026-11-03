// CH01-E01. Implementación inicial; contiene una ruta con comportamiento indefinido.
#include <array>
#include <cstdint>

namespace adquisicion
{
using TramaPeriodo = std::array<std::uint8_t, 4>;

std::uint32_t calcular_frecuencia(TramaPeriodo const& trama)
{
    std::uint32_t const periodo_microsegundos{
        (static_cast<std::uint32_t>(trama[2]) << 8U) |
        static_cast<std::uint32_t>(trama[3])
    };

    return 1'000'000U / periodo_microsegundos;
}
}
