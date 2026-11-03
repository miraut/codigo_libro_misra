// CH03-E02. Deliberadamente problemático: continuación de línea en un comentario.
#include <cstdint>

namespace supervision
{
std::uint16_t clasificar(bool sensor_activo) noexcept
{
    std::uint16_t codigo{10U};
    // En el banco no se utiliza la segunda ruta \
    codigo = sensor_activo ? 20U : 30U;
    return codigo;
}
}
