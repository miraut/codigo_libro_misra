// CH15-E02. Riesgo de lectura no inicializada si falla la llamada.
// No ejecutar: se mantiene deliberadamente la infraccion semantica.
#include "adquisicion.hpp"
#include <cstdint>

std::uint32_t adquirir_sin_atender_al_estado(adquisicion::Sensor const& sensor) noexcept
{
    std::uint32_t muestra;
    (void)adquisicion::leer_sensor(sensor, muestra);
    return muestra;
}
