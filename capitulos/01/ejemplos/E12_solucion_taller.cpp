// CH01-E12. Solucion al taller, con capacidad fija y estados explicitos.
#include <array>
#include <cstddef>
#include <cstdint>

namespace adquisicion
{
constexpr std::size_t capacidad_periodos{8U};

enum class EstadoProceso
{
    correcto,
    sin_periodos,
    periodo_ausente,
    capacidad_superada
};

struct ResultadoProceso
{
    EstadoProceso estado;
    std::uint32_t ultima_frecuencia;
};

ResultadoProceso procesar_periodos(
    std::array<std::uint32_t, capacidad_periodos> const& periodos,
    std::size_t cantidad) noexcept
{
    if (cantidad > periodos.size())
    {
        return {EstadoProceso::capacidad_superada, 0U};
    }
    if (cantidad == 0U)
    {
        return {EstadoProceso::sin_periodos, 0U};
    }

    for (std::size_t indice{0U}; indice < cantidad; ++indice)
    {
        if (periodos[indice] == 0U)
        {
            return {EstadoProceso::periodo_ausente, 0U};
        }
    }

    return {EstadoProceso::correcto, 1'000'000U / periodos[cantidad - 1U]};
}
}
