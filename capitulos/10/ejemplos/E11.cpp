// CH10-E11. Comprobación estática y validación de una condición de ejecución.
#include <cassert>
#include <cstdint>
#include <limits>

namespace ejemplo_aserciones
{
static_assert(std::numeric_limits<std::uint32_t>::digits == 32,
              "La representacion requiere 32 bits de valor");

bool procesar_con_precondicion(std::uint32_t medida,
                               bool canal_configurado) noexcept
{
    assert(canal_configurado); // El llamador debe garantizarlo.
    return medida <= 4095U;
}

bool validar_entrada_externa(std::uint32_t medida,
                             bool canal_configurado) noexcept
{
    if (!canal_configurado)
    {
        return false;
    }
    return medida <= 4095U;
}
}
