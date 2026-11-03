#include "adquisicion.hpp"

#if !defined(CH15_VARIANTE_LABORATORIO) && !defined(CH15_VARIANTE_EQUIPO)
#error "Es obligatorio seleccionar una variante de producto"
#endif

#if defined(CH15_VARIANTE_LABORATORIO) && defined(CH15_VARIANTE_EQUIPO)
#error "Las variantes de producto son excluyentes"
#endif

namespace adquisicion
{
ResultadoLectura obtener_medida(Sensor const& sensor,
                               std::uint32_t divisor) noexcept
{
    std::uint32_t muestra{0U};
    if (!leer_sensor(sensor, muestra))
    {
        return {EstadoLectura::sensor_no_disponible, 0U};
    }
    if (divisor == 0U)
    {
        return {EstadoLectura::divisor_invalido, 0U};
    }

    return {EstadoLectura::correcta, muestra / divisor};
}
} // namespace adquisicion
