#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E08.cpp"
int main()
{
    assert(signo::suma_modular(80U,-100)==4294967276U); assert(!signo::suma_del_dominio(80U,-100).has_value()); assert(signo::suma_del_dominio(80U,-20).value()==60U);
    return 0;
}
