// CH14-E12. Uso problemático: ejecución de una orden construida como texto.
#include <cstdlib>
#include <string>

namespace mantenimiento
{
int ejecutar_orden(std::string const& orden)
{
    return std::system(orden.c_str());
}
}
