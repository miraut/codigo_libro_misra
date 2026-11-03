#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E07.cpp"
int main()
{
    assert(promociones::sumar_octetos(std::uint8_t{250U},std::uint8_t{250U})==500U);
    return 0;
}
