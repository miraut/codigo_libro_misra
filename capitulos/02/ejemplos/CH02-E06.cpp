// CH02-E06. Expresión de control invariante para un tipo sin signo.
#include <cstdint>

bool comprobar_valor(std::uint32_t cantidad) noexcept
{
    if (cantidad >= 0U)
    {
        return true;
    }
    return false;
}
