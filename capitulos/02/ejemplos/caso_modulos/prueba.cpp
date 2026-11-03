#include "lectura.hpp"
#include <cassert>

int main()
{
    caso_modulos::Muestras const muestras{{11U, 22U, 33U, 44U}};
    std::uint16_t salida{99U};
    assert(caso_modulos::atender_solicitud_validada(muestras, 3U, salida));
    assert(salida == 44U);
    assert(!caso_modulos::atender_solicitud_validada(muestras, 4U, salida));
    assert(salida == 44U);
    // NO invocar atender_solicitud_sin_validar con indice 4: es inseguro.
    assert(caso_modulos::atender_solicitud_sin_validar(muestras, 0U, salida));
    assert(salida == 11U);
}
