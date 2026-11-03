#include "configuracion_equipo.hpp"
#include "fuente_medidas.hpp"
#include <cassert>

int main()
{
#if MODO_EQUIPO == MODO_LABORATORIO
    assert(adquisicion::obtener_medida(325U) == 120U);
#else
    assert(adquisicion::obtener_medida(325U) == 325U);
#endif
    return 0;
}
