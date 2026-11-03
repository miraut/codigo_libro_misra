#include <cassert>
#include "../ejemplos/CH02-E04.cpp"
int main()
{
    supervision::Muestras const muestras{{10U, 20U, 30U, 40U}};
    auto const correcto{supervision::IndiceCanal::crear(3U)};
    assert(correcto.has_value());
    assert(supervision::extraer_canal(muestras, *correcto) == 40U);
    auto const incorrecto{supervision::IndiceCanal::crear(4U)};
    assert(!incorrecto.has_value());
}
