#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E22.cpp"
int main()
{
    std::uint32_t n=0x1020'3040U; [[maybe_unused]] auto primer=representacion::primer_byte(n); [[maybe_unused]] auto direccion=representacion::direccion_numerica(&n);
    return 0;
}
