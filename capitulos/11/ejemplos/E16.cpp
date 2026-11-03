// CH11-E16. Problemático para MISRA: salto hacia el interior de un bloque.
#include <cstdint>

namespace ejemplo_salto_entrante
{
std::uint32_t entrar_en_bloque() noexcept
{
    std::uint32_t resultado{0U};
    goto actualizar;

    {
    actualizar:
        resultado = 5U;
    }

    return resultado;
}
}
