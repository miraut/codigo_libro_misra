// CH05-E21. Parametro de salida con garantia de no modificar en caso de error.
#include <array>
#include <cstdint>

namespace salida_controlada {
using Trama = std::array<std::uint8_t, 3U>;

struct Lectura {
    std::uint8_t canal{0U};
    std::uint8_t valor{0U};
};

bool intentar_decodificar(Trama const& trama, Lectura& destino) noexcept
{
    if ((trama[0U] != 0xA5U) || (trama[1U] >= 4U))
    {
        return false;
    }

    Lectura const candidata{trama[1U], trama[2U]};
    destino = candidata;
    return true;
}
} // namespace salida_controlada
