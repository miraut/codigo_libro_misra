#include <cassert>
#include <cstdint>
#include <string_view>

#include "../caso_integrador/configuracion.hpp"

int main()
{
    using equipo::Configuracion;
    using equipo::ErrorConfiguracion;
    using equipo::Modo;
    Configuracion estado{20U, Modo::pausa};
    assert(equipo::interpretar("version=1;periodo_ms=50;modo=activo", estado)
           == ErrorConfiguracion::ninguno);
    assert(estado.periodo_ms == 50U && estado.modo == Modo::activo);
    assert(equipo::interpretar("version=1;periodo_ms=1000;modo=pausa", estado)
           == ErrorConfiguracion::ninguno);
    assert(estado.periodo_ms == 1000U && estado.modo == Modo::pausa);

    struct CasoError
    {
        std::string_view mensaje;
        ErrorConfiguracion esperado;
    };
    CasoError const casos[]{
        {"", ErrorConfiguracion::formato},
        {"version=1;periodo_ms=50", ErrorConfiguracion::formato},
        {"version=1;periodo_ms=50;modo=activo;extra", ErrorConfiguracion::formato},
        {"version=1;periodo_ms=50;modo=activo;", ErrorConfiguracion::formato},
        {"version=2;periodo_ms=50;modo=activo", ErrorConfiguracion::version},
        {"version=+1;periodo_ms=50;modo=activo", ErrorConfiguracion::formato},
        {"version=1x;periodo_ms=50;modo=activo", ErrorConfiguracion::formato},
        {"version=1;periodo_ms=4;modo=activo", ErrorConfiguracion::periodo},
        {"version=1;periodo_ms=1001;modo=activo", ErrorConfiguracion::periodo},
        {"version=1;periodo_ms=5ms;modo=activo", ErrorConfiguracion::periodo},
        {"version=1;periodo_ms=99999999999999;modo=activo", ErrorConfiguracion::periodo},
        {"version=1;periodo_ms=50;modo=normal", ErrorConfiguracion::modo},
        {"version=1;periodo_ms=50;modo=ACTIVO", ErrorConfiguracion::modo},
        {"VERSION=1;periodo_ms=50;modo=activo", ErrorConfiguracion::formato},
        {"version=1;periodo=50;modo=activo", ErrorConfiguracion::formato},
    };
    for (auto const& caso : casos)
    {
        assert(equipo::interpretar(caso.mensaje, estado) == caso.esperado);
        assert(estado.periodo_ms == 1000U && estado.modo == Modo::pausa);
    }
    assert(equipo::interpretar("version=1;periodo_ms=5;modo=activo", estado)
           == ErrorConfiguracion::ninguno);
    assert(estado.periodo_ms == 5U && estado.modo == Modo::activo);
    return 0;
}
