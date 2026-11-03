#include "adquisicion.hpp"

namespace adquisicion
{
bool leer_sensor(Sensor const& sensor, std::uint32_t& muestra) noexcept
{
    if (!sensor.disponible)
    {
        return false;
    }
    muestra = sensor.muestra_bruta;
    return true;
}
} // namespace adquisicion
