// CH05-E15. Desplazamiento a la derecha con std::copy_backward.
#include <algorithm>
#include <array>
#include <cstdint>

namespace desplazamiento_derecha {
using Historia = std::array<std::uint16_t, 6U>;

void dejar_espacio_al_principio(Historia& datos) noexcept
{
    // Copia [0, 4) sobre [1, 5), desde el extremo derecho.
    std::copy_backward(datos.begin(), datos.begin() + 4, datos.begin() + 5);
}
} // namespace desplazamiento_derecha
