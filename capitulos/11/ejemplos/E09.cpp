// CH11-E09. Contador estable y recorrido completo.
#include <array>
#include <cstddef>

namespace ejemplo_contador_revisado
{
std::size_t contar_rechazos(
    std::array<bool, 5U> const& muestras_rechazadas) noexcept
{
    std::size_t rechazadas{0U};

    for (std::size_t indice{0U}; indice < muestras_rechazadas.size(); ++indice)
    {
        if (muestras_rechazadas[indice])
        {
            ++rechazadas;
        }
    }

    return rechazadas;
}
}
