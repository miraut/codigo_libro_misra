#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E23.cpp"
int main()
{
    auto puntero=funciones::tipo_correcto(); assert(puntero(27U)==27U); // No llamar a tipo_incompatible().
    return 0;
}
