// CH10-E09. El contrato noexcept requiere revisar el recorrido de la excepción.
#include <cstdint>

namespace ejemplo_noexcept
{
struct ErrorRango {};

void comprobar_rango(std::int32_t valor)
{
    if (valor < 0)
    {
        throw ErrorRango{};
    }
}

void comprobar_sin_control(std::int32_t valor) noexcept
{
    comprobar_rango(valor); // Problemático para valores negativos.
}

bool comprobar_con_control(std::int32_t valor) noexcept
{
    try
    {
        comprobar_rango(valor);
        return true;
    }
    catch (ErrorRango const&)
    {
        return false;
    }
}
}
