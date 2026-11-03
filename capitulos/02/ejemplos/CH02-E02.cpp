// CH02-E02. La llamada puede incumplir la precondición de la función invocada.
#include <array>
#include <cstddef>
#include <cstdint>

namespace supervision
{
using Muestras = std::array<std::uint16_t, 4>;

// Precondición de esta interfaz: indice < muestras.size().
std::uint16_t extraer_canal(Muestras const& muestras,
                            std::size_t indice) noexcept
{
    return muestras[indice];
}

std::uint16_t extraer_seleccion(Muestras const& muestras,
                                std::size_t indice) noexcept
{
    return extraer_canal(muestras, indice); // No establece la precondición.
}
}
