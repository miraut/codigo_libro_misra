// CH11-E15. Problemático: goto retrocede a una etiqueta anterior.
#include <cstdint>

namespace ejemplo_salto_retroceso
{
std::uint32_t contar_tres_iteraciones() noexcept
{
    std::uint32_t contador{0U};

repetir:
    ++contador;

    if (contador < 3U)
    {
        goto repetir;
    }

    return contador;
}
}
