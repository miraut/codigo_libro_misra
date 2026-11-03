#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E24.cpp"
int main()
{
    hardware::LectorSimulado lector{8U}; assert(hardware::comprobar_mascara(lector)); hardware::LectorSimulado otro{0U}; assert(!hardware::comprobar_mascara(otro)); // No acceder a direccion fisica.
    return 0;
}
