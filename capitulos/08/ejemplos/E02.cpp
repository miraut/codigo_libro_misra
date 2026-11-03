// CH08-E02. Problemático: se ignora el resultado de la comprobación.
#include <cstdint>

bool calibracion_aceptable(std::uint32_t lectura) noexcept
{
    return lectura <= 4095U;
}

void habilitar_actuador() noexcept;

void procesar_calibracion(std::uint32_t lectura) noexcept
{
    calibracion_aceptable(lectura); // El resultado se descarta.
    habilitar_actuador();
}
