// CH11-E12. El contenedor temporal exterior vive durante el for de rango.
#include <array>
#include <cstdint>

namespace ejemplo_temporal_exterior
{
std::array<std::uint32_t, 3U> obtener_muestras() noexcept
{
    return {{4U, 5U, 6U}};
}

std::uint32_t sumar_muestras() noexcept
{
    std::uint32_t suma{0U};
    for (std::uint32_t muestra : obtener_muestras())
    {
        suma += muestra;
    }
    return suma;
}
}
