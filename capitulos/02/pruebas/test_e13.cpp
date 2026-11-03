#include <cassert>
#include "../ejemplos/CH02-E13_solucion.cpp"
int main()
{
    supervision::Muestras const muestras{{10U, 20U, 30U, 40U}};
    std::uint16_t salida{99U};
    assert(supervision::obtener_muestra(muestras, 0U, salida));
    assert(salida == 10U);
    assert(supervision::obtener_muestra(muestras, 3U, salida));
    assert(salida == 40U);
    assert(!supervision::obtener_muestra(muestras, 4U, salida));
    assert(salida == 40U);
}
