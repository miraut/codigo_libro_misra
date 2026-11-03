// CH15-E09. Condicion de overflow explicita para entradas no negativas.
#include <cstdint>
#include <limits>

bool acumular_sin_desbordamiento(std::uint32_t acumulado,
                                std::uint32_t incremento,
                                std::uint32_t& resultado) noexcept
{
    auto const maximo = std::numeric_limits<std::uint32_t>::max();
    if (incremento > maximo - acumulado)
    {
        return false;
    }
    resultado = acumulado + incremento;
    return true;
}
