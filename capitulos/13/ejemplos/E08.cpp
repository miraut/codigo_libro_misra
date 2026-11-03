// CH13-E08. Comprobación de la presencia y el valor de una opción.
#ifndef EQUIPO_EN_CAMPO
#error "EQUIPO_EN_CAMPO debe definirse en la configuracion"
#elif (EQUIPO_EN_CAMPO != 0) && (EQUIPO_EN_CAMPO != 1)
#error "EQUIPO_EN_CAMPO debe valer 0 o 1"
#endif

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
