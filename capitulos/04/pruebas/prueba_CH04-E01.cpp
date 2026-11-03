#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E01.cpp"
int main()
{
    auto r=apertura::evaluar(80U,-100,1000U); assert(r.pulsos_corregidos==4294967276U); assert(r.alarma);
    return 0;
}
