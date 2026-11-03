// CH04-E26. Tres resultados y rechazo explícito de entradas no finitas.
#include <cmath>
#include <optional>

namespace temperatura
{
enum class Dictamen { normal, indeterminado, alarma };

struct Limites
{
    double umbral_celsius;
    double tolerancia_celsius;
};

std::optional<Dictamen> evaluar(double lectura_celsius,
                               Limites limites)
{
    if (!std::isfinite(lectura_celsius) ||
        !std::isfinite(limites.umbral_celsius) ||
        !std::isfinite(limites.tolerancia_celsius) ||
        (limites.tolerancia_celsius < 0.0))
    {
        return std::nullopt;
    }

    double const limite_inferior =
        limites.umbral_celsius - limites.tolerancia_celsius;
    double const limite_superior =
        limites.umbral_celsius + limites.tolerancia_celsius;

    if (!std::isfinite(limite_inferior) ||
        !std::isfinite(limite_superior))
    {
        return std::nullopt;
    }

    if (lectura_celsius < limite_inferior)
    {
        return Dictamen::normal;
    }
    if (lectura_celsius > limite_superior)
    {
        return Dictamen::alarma;
    }
    return Dictamen::indeterminado;
}
}
