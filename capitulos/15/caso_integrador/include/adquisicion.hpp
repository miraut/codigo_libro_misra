#ifndef CH15_ADQUISICION_HPP
#define CH15_ADQUISICION_HPP

#include <cstdint>

namespace adquisicion
{
struct Sensor
{
    bool disponible{false};
    std::uint32_t muestra_bruta{0U};
};

enum class EstadoLectura
{
    correcta,
    sensor_no_disponible,
    divisor_invalido
};

struct ResultadoLectura
{
    EstadoLectura estado{EstadoLectura::sensor_no_disponible};
    std::uint32_t medida{0U};
};

bool leer_sensor(Sensor const& sensor, std::uint32_t& muestra) noexcept;

ResultadoLectura obtener_medida(Sensor const& sensor,
                               std::uint32_t divisor) noexcept;

} // namespace adquisicion
#endif
