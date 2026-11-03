// CH10-E01. Problemático: el destructor realiza una operación que puede lanzar.
#include <cstdint>

namespace ejemplo_apertura
{
struct ErrorLectura {};

void guardar_diagnostico(std::uint32_t codigo); // Puede lanzar una excepción.

class SesionAdquisicion
{
public:
    ~SesionAdquisicion() noexcept
    {
        guardar_diagnostico(17U);
    }
};

void atender_lectura()
{
    SesionAdquisicion sesion{};
    throw ErrorLectura{};
}
}
