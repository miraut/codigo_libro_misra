// CH14-E10. Implementación problemática: concatenación sin capacidad suficiente.
#include <cstring>

namespace diagnostico
{
void preparar_etiqueta()
{
    char etiqueta[6]{'i', 'd', '=', '\0', '\0', '\0'};
    std::strcat(etiqueta, "123456");
}
}
