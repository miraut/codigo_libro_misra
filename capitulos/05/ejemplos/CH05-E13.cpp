// CH05-E13. memcpy sobre regiones solapadas: no ejecutar esta funcion.
#include <array>
#include <cstdint>
#include <cstring>

namespace copia_solapada {
using Historia = std::array<std::uint16_t, 6U>;

void desplazar_con_memcpy(Historia& datos) noexcept
{
    // Origen [1, 5), destino [0, 4): las regiones se solapan.
    (void)std::memcpy(&datos[0U], &datos[1U],
                      4U * sizeof(datos[0U]));
    // Infraccion Mandatory de Rule 8.18.1 y comportamiento indefinido.
}
} // namespace copia_solapada
