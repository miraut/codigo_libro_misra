// CH05-E14. Desplazamiento a la izquierda con std::copy.
#include <algorithm>
#include <array>
#include <cstdint>

namespace desplazamiento_izquierda {
using Historia = std::array<std::uint16_t, 6U>;

void eliminar_primera(Historia& datos) noexcept
{
    // Copia [1, 5) sobre [0, 4); destino empieza fuera del rango origen.
    std::copy(datos.begin() + 1, datos.begin() + 5, datos.begin());
}
} // namespace desplazamiento_izquierda
