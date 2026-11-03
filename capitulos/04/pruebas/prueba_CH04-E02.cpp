#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E02.cpp"
int main()
{
    assert(!conversion_validada::corregir(80U,-100).has_value()); assert(conversion_validada::corregir(80U,-20).value()==60U); assert(!conversion_validada::corregir(0U,-1).has_value());
    return 0;
}
