#include <cassert>
#include <cstdint>
#include <limits>
#include "../ejemplos/CH02-E06.cpp"
int main()
{
    assert(comprobar_valor(0U));
    assert(comprobar_valor(std::numeric_limits<std::uint32_t>::max()));
}
