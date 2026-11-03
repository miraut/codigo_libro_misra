#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E16.cpp"
int main()
{
    assert(enumeracion_simbolica::es_critico(enumeracion_simbolica::parada)); assert(!enumeracion_simbolica::es_critico(enumeracion_simbolica::ninguno)); assert(enumeracion_simbolica::elegir(true)==enumeracion_simbolica::parada);
    return 0;
}
