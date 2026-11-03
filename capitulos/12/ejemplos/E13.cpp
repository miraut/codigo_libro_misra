// CH12-E13. Copia acotada de una opción del entorno antes de otras consultas.
#include <array>
#include <cstddef>
#include <cstdlib>

namespace ejemplo_copia_entorno
{
using TextoCorto = std::array<char, 32>;

bool copiar_cadena(char const* origen, TextoCorto& destino) noexcept
{
    if (origen == nullptr)
    {
        return false;
    }

    for (std::size_t indice{0U}; indice < destino.size(); ++indice)
    {
        char const caracter{origen[indice]};
        destino[indice] = caracter;
        if (caracter == '\0')
        {
            return true;
        }
    }

    destino.back() = '\0';
    return false; // El texto no cabía: el llamador debe tratarlo como error.
}

bool copiar_opcion(char const* nombre, TextoCorto& destino) noexcept
{
    if (nombre == nullptr)
    {
        return false;
    }

    char const* const valor{std::getenv(nombre)};
    return copiar_cadena(valor, destino); // Antes de una nueva llamada a getenv.
}
}
