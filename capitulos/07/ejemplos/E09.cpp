// CH07-E09. Límites del mismo array.
#include <array>
#include <cstdint>

namespace protocolo
{
void revisar_limites() noexcept
{
    std::array<std::uint8_t, 5U> trama{{1U, 2U, 3U, 4U, 5U}};

    auto* inicio = trama.data();
    auto* fin = inicio + trama.size(); // Posición posterior al último elemento.

    (void)fin; // No se desreferencia.

    // Problemático: formar inicio + 6U ya excedería el intervalo permitido.
}
}
