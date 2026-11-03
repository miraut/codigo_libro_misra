#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E12.cpp"
int main()
{
    assert(unarios::negar_modular(1U)==0xFFFF'FFFFU); assert(unarios::cambio_de_signo(0xFFFF'FFFFU)==-4294967295LL);
    return 0;
}
