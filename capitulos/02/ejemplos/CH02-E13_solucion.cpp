// CH02-E13. Solucion independiente y verificable del taller del capitulo 2.
#include <array>
#include <cstddef>
#include <cstdint>

namespace supervision
{
using Muestras = std::array<std::uint16_t, 4>;

bool obtener_muestra(Muestras const& muestras,
                     std::size_t canal,
                     std::uint16_t& salida) noexcept
{
    if (canal >= muestras.size())
    {
        return false;
    }

    salida = muestras[canal];
    return true;
}
}
