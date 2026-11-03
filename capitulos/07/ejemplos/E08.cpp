// CH07-E08. Interfaz con longitud fijada en el tipo.
#include <array>
#include <cstdint>

namespace protocolo
{
using Cabecera = std::array<std::uint8_t, 8U>;

std::uint8_t leer_campo(Cabecera const& bytes) noexcept
{
    return bytes[7U];
}
}
