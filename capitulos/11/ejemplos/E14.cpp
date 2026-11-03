// CH11-E14. Salto hacia adelante a un bloque envolvente.
#include <cstdint>

namespace ejemplo_salto_acotado
{
std::uint32_t obtener_resultado(bool condicion_invalida) noexcept
{
    std::uint32_t resultado{0U};

    if (condicion_invalida)
    {
        goto terminar;
    }

    resultado = 7U;

terminar:
    return resultado;
}
}
