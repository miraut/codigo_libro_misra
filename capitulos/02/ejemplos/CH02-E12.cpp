// CH02-E12. Ejercicio: detectar y distinguir las anomalías.
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
    std::uint16_t muestra{0U};

    if (canal > muestras.size())
    {
        return false;
    }

    muestra = muestras[canal];

    if (canal >= 0U)
    {
        salida = muestra;
        return true;
    }

    return false;
    salida = 0U;
}
}
