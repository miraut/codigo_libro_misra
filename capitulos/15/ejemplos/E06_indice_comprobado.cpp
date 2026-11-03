// CH15-E06. Acceso tras comprobar el limite del arreglo.
#include <array>
#include <cstddef>
#include <cstdint>

bool obtener_canal(std::array<std::uint16_t, 8> const& canales,
                   std::size_t indice,
                   std::uint16_t& resultado) noexcept
{
    if (indice >= canales.size())
    {
        return false;
    }
    resultado = canales[indice];
    return true;
}
