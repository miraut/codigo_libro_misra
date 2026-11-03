// CH07-E11. Problemático. No ejecutar estas operaciones.
#include <array>
#include <cstdint>

namespace protocolo
{
void comparar_fragmentos() noexcept
{
    std::array<std::uint8_t, 3U> cabecera{{1U, 2U, 3U}};
    std::array<std::uint8_t, 3U> datos{{4U, 5U, 6U}};

    auto* pc = cabecera.data();
    auto* pd = datos.data();

    auto distancia = pd - pc; // Comportamiento indefinido: arrays distintos.
    auto anterior = pc < pd;  // Orden nativo inadecuado entre arrays distintos.

    (void)distancia;
    (void)anterior;
}
}
