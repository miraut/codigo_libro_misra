#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E03.cpp"
int main()
{
    assert(dominio::pertenece(dominio::NumeroPulsos{9U},dominio::Canal{4U})); assert(!dominio::pertenece(dominio::NumeroPulsos{0U},dominio::Canal{4U}));
    return 0;
}
