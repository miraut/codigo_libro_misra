// CH08-E03. El resultado determina si la operación puede continuar.
#include <cstdint>

bool calibracion_aceptable(std::uint32_t lectura) noexcept
{
    return lectura <= 4095U;
}

void habilitar_actuador() noexcept;
void registrar_calibracion_rechazada(std::uint32_t lectura) noexcept;

void procesar_calibracion(std::uint32_t lectura) noexcept
{
    if (calibracion_aceptable(lectura))
    {
        habilitar_actuador();
    }
    else
    {
        registrar_calibracion_rechazada(lectura);
    }
}
