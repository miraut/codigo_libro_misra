// CH01-E07. Alternativa disponible desde C++17.
#include <exception>

bool hay_excepcion_pendiente() noexcept
{
    return std::uncaught_exceptions() > 0;
}
