// CH12-E14. Una copia de std::tm conserva los campos ya obtenidos.
#include <ctime>

namespace ejemplo_fecha_hora
{
bool descomponer_utc(std::time_t instante, std::tm& resultado)
{
    std::tm const* const fecha{std::gmtime(&instante)};
    if (fecha == nullptr)
    {
        return false;
    }

    resultado = *fecha;
    return true;
}
}
