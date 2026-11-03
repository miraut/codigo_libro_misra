#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E20.cpp"
int main()
{
    assert(tipos_de_cast::estrechamiento_legado(70000U)==4464U); assert(!tipos_de_cast::estrechamiento_verificado(70000U).has_value()); assert(tipos_de_cast::estrechamiento_verificado(100U).value()==100U);
    return 0;
}
