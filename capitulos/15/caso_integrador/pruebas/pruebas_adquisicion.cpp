#include "adquisicion.hpp"

int main()
{
    using adquisicion::EstadoLectura;
    using adquisicion::Sensor;

    Sensor const sensor_disponible{true, 120U};
    Sensor const sensor_ausente{false, 0U};

    auto const resultado_correcto = adquisicion::obtener_medida(sensor_disponible, 4U);
    if ((resultado_correcto.estado != EstadoLectura::correcta) ||
        (resultado_correcto.medida != 30U))
    {
        return 1;
    }

    auto const divisor_nulo = adquisicion::obtener_medida(sensor_disponible, 0U);
    if ((divisor_nulo.estado != EstadoLectura::divisor_invalido) ||
        (divisor_nulo.medida != 0U))
    {
        return 2;
    }

    auto const sensor_fallido = adquisicion::obtener_medida(sensor_ausente, 4U);
    if ((sensor_fallido.estado != EstadoLectura::sensor_no_disponible) ||
        (sensor_fallido.medida != 0U))
    {
        return 3;
    }

    return 0;
}
