#include <cassert>
#include "../ejemplos/CH02-E03.cpp"
int main()
{
    supervision::Muestras const muestras{{10U, 20U, 30U, 40U}};
    auto const valida{supervision::leer_canal(muestras, 3U)};
    assert(valida.correcta && valida.valor == 40U);
    auto const invalida{supervision::leer_canal(muestras, 4U)};
    assert(!invalida.correcta);
}
