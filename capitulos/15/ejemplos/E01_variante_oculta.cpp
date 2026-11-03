// CH15-E01. Caso de riesgo: deliberadamente no ejecutar con cantidad == 0.
// Se compila por separado con CH15_VARIANTE_LABORATORIO o CH15_VARIANTE_EQUIPO.
#include <cstdint>

std::uint32_t calcular_promedio_inseguro(std::uint32_t acumulado,
                                       std::uint32_t cantidad) noexcept
{
#if defined(CH15_VARIANTE_LABORATORIO)
    if (cantidad == 0U)
    {
        return 0U;
    }
#endif
    return acumulado / cantidad;
}
