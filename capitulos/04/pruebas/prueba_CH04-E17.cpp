#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E17.cpp"
int main()
{
    campos::RegistroDePrueba r{}; r.codigo=6U; r.alarma=true; assert(r.codigo==6U); assert(r.alarma);
    return 0;
}
