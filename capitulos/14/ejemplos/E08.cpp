// CH14-E08. atoi no informa de forma suficiente sobre entradas incorrectas.
#include <cstdlib>

namespace configuracion
{
int interpretar_periodo_sin_validacion()
{
    int const periodo_vacio = std::atoi("texto");
    int const periodo_cero = std::atoi("0");
    return periodo_vacio + periodo_cero;
}
}
