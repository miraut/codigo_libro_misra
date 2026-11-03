// CH13-E01. Selección condicionada por una macro que podría no existir.
#include <cstdint>

namespace supervision
{
std::uint16_t consultar_entrada(std::uint16_t lectura_fisica) noexcept
{
#if EQUIPO_EN_CAMPO == 1
    return lectura_fisica;
#else
    (void)lectura_fisica;
    return 0U;
#endif
}
}
