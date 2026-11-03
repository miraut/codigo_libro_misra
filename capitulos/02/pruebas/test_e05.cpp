#include <cassert>
#include "../ejemplos/CH02-E05.cpp"
int main()
{
    assert(supervision::seleccionar_valor(0U) == 0U);
    assert(supervision::seleccionar_valor(1U) == 1U);
    assert(supervision::seleccionar_valor(99U) == 99U);
}
