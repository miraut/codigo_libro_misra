#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E19.cpp"
int main()
{
    auto a=alternativas::analizar(true,42U); assert(alternativas::contiene_medida(a)); auto b=alternativas::analizar(false,42U); assert(!alternativas::contiene_medida(b));
    return 0;
}
