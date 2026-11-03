#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E15.cpp"
int main()
{
    assert(static_cast<std::uint8_t>(valores_enumerados::EstadosConColision::activo)==static_cast<std::uint8_t>(valores_enumerados::EstadosConColision::revision)); assert(static_cast<std::uint8_t>(valores_enumerados::EstadosConAlias::revision)==2U);
    return 0;
}
