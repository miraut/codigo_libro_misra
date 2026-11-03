// CH01-E06. API obsoleta en C++17, conservada para compatibilidad.
#include <exception>

bool hay_excepcion_pendiente() noexcept
{
    return std::uncaught_exception();
}
