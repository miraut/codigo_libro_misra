// CH05-E02. Una estructura y un array no se inicializan por simpatia.
#include <array>
#include <cstdint>

namespace objetos_discretos {
struct Medida {
    std::uint16_t canal;
    std::uint16_t intensidad;
};

std::uint16_t leer_intensidad(bool dato_disponible) noexcept
{
    Medida lectura; // Ambos miembros necesitan un valor antes de su lectura.
    lectura.canal = 2U;
    if (dato_disponible)
    {
        lectura.intensidad = 415U;
    }
    return lectura.intensidad; // No ejecutar con dato_disponible == false.
}

std::uint16_t ultimo_valor() noexcept
{
    std::array<std::uint16_t, 3U> muestras{{12U, 18U, 0U}};
    return muestras[2U]; // El tercer elemento tiene un valor definido.
}
} // namespace objetos_discretos
