#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E14.cpp"
int main()
{
    assert(estados::interpretar(std::uint8_t{1U}).value()==estados::Estado::midiendo); assert(!estados::interpretar(std::uint8_t{255U}).has_value());
    return 0;
}
