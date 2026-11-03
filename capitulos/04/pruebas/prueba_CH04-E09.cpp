#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E09.cpp"
int main()
{
    assert(asignaciones::ampliar(100U)==100U); assert(asignaciones::estrechar(65535U).value()==65535U); assert(!asignaciones::estrechar(65536U).has_value());
    return 0;
}
