// CH04-E04. Codificar un estado lógico sin convertir bool en un entero.
#include <cstdint>

namespace logica
{
std::uint8_t codificar_alarma(bool activada) noexcept
{
    return activada ? std::uint8_t{1U} : std::uint8_t{0U};
}

bool decodificar_alarma(std::uint8_t dato, bool& resultado) noexcept
{
    if (dato == 0U)
    {
        resultado = false;
        return true;
    }
    if (dato == 1U)
    {
        resultado = true;
        return true;
    }
    return false;
}
}
