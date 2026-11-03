#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E11.cpp"
int main()
{
    assert(mascaras::extraer(std::uint8_t{0xABU})==0xAB00U); assert(mascaras::bandera(31U).value()==0x80000000U); assert(!mascaras::bandera(32U).has_value());
    return 0;
}
