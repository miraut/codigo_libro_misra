// CH01-E02. La condición del protocolo se comprueba antes de calcular.
#include <cstdint>

namespace adquisicion
{
enum class EstadoFrecuencia
{
    valida,
    sin_medida
};

struct ResultadoFrecuencia
{
    EstadoFrecuencia estado;
    std::uint32_t hercios;
};

ResultadoFrecuencia calcular_frecuencia(std::uint32_t periodo_microsegundos) noexcept
{
    if (periodo_microsegundos == 0U)
    {
        return {EstadoFrecuencia::sin_medida, 0U};
    }

    return {EstadoFrecuencia::valida, 1'000'000U / periodo_microsegundos};
}
}
