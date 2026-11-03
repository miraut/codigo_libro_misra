#include "configuracion_equipo.hpp"
#include "fuente_medidas.hpp"

namespace adquisicion
{
std::uint16_t obtener_medida(std::uint16_t lectura_dispositivo) noexcept
{
#if MODO_EQUIPO == MODO_LABORATORIO
    (void)lectura_dispositivo;
    return 120U;
#else
    return lectura_dispositivo;
#endif
}
}
