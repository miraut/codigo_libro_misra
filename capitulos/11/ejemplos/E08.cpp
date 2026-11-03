// CH11-E08. Problemático: el contador se modifica dentro del cuerpo.
#include <array>
#include <cstddef>

namespace ejemplo_contador_alterado
{
std::size_t contar_posiciones_revisadas(
    std::array<bool, 5U> const& muestras_rechazadas) noexcept
{
    std::size_t revisadas{0U};

    for (std::size_t indice{0U}; indice < muestras_rechazadas.size(); ++indice)
    {
        ++revisadas;
        if (muestras_rechazadas[indice])
        {
            ++indice;
        }
    }

    return revisadas;
}
}
