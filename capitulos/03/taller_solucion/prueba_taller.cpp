#include "registro.hpp"

int main()
{
    supervision::Registro registro{};
    auto const primero{supervision::cliente_a(registro)};
    auto const segundo{supervision::cliente_b(registro)};
    if (!primero.valido || primero.total != 1U)
    {
        return 1;
    }
    if (!segundo.valido || segundo.total != 3U)
    {
        return 2;
    }
    supervision::Registro independiente{};
    auto const tercero{supervision::cliente_b(independiente)};
    if (!tercero.valido || tercero.total != 2U)
    {
        return 3;
    }
    return 0;
}
