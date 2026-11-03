// CH07-E07. Interfaz problemática por pérdida de tamaño.
#include <cstdint>

namespace protocolo
{
std::uint8_t leer_campo(std::uint8_t const* bytes) noexcept
{
    return bytes[7U]; // Requiere, externamente, al menos ocho elementos.
}

void llamada_problemática() noexcept
{
    std::uint8_t corto[4U]{1U, 2U, 3U, 4U};
    (void)leer_campo(corto); // No ejecutar: pierde tamaño y accede fuera.
}
}
