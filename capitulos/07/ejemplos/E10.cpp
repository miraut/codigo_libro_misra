// CH07-E10. Validación de un subrango antes de calcular direcciones.
#include <cstddef>

namespace protocolo
{
bool subrango_valido(std::size_t comienzo,
                    std::size_t longitud,
                    std::size_t capacidad) noexcept
{
    return (comienzo <= capacidad) &&
           (longitud <= (capacidad - comienzo));
}
}
