#include "../caso_integrador/receptor.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <string_view>

int main()
{
    equipo::Configuracion estado{20U, equipo::Modo::pausa};
    std::array<char, 96U> datos{};
    std::string_view const valido{"version=1;periodo_ms=50;modo=activo"};
    std::copy(valido.begin(), valido.end(), datos.begin());
    assert(equipo::procesar_bloque(datos, valido.size(), estado)
        == equipo::ErrorConfiguracion::ninguno);
    assert(estado.periodo_ms == 50U);
    assert(estado.modo == equipo::Modo::activo);
    assert(equipo::procesar_bloque(datos, datos.size() + 1U, estado)
        == equipo::ErrorConfiguracion::formato);
    assert(estado.periodo_ms == 50U);
    assert(equipo::procesar_bloque(datos, 0U, estado)
        == equipo::ErrorConfiguracion::formato);
    assert(estado.modo == equipo::Modo::activo);
    return 0;
}
