#include <cassert>
#include "../ejemplos/CH02-E11.cpp"
int main()
{
    supervision::Muestras const muestras{{10U, 0U, 30U, 40U}};
    supervision::RegistroAdquisicion registro;
    auto invalido{supervision::evaluar_canal(muestras, 4U, registro)};
    assert(invalido.estado == supervision::EstadoMedida::canal_invalido);
    assert(registro.cantidad_registros() == 0U);
    auto ausente{supervision::evaluar_canal(muestras, 1U, registro)};
    assert(ausente.estado == supervision::EstadoMedida::ausente);
    assert(registro.cantidad_registros() == 1U);
    auto primero{supervision::evaluar_canal(muestras, 0U, registro)};
    assert(primero.estado == supervision::EstadoMedida::valida);
    assert(primero.valor == 10U);
    assert(registro.cantidad_registros() == 2U);
    auto ultimo{supervision::evaluar_canal(muestras, 3U, registro)};
    assert(ultimo.estado == supervision::EstadoMedida::valida);
    assert(ultimo.valor == 40U);
    assert(registro.cantidad_registros() == 3U);
}
