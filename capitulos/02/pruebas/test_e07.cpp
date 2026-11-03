#include <cassert>
#include "../ejemplos/CH02-E07.cpp"
int main()
{
    assert(preparar_lectura(23U) == 23U);
    assert(preparar_lectura(0U) == 0U);
}
