// CH10-E02. Preparar y validar antes de actualizar el estado observable.
#include <cstdint>

namespace ejemplo_configuracion
{
struct Configuracion
{
    std::uint32_t limite_alarma{0U};
    std::uint32_t limite_seguridad{0U};
};

bool actualizar_configuracion(Configuracion& configuracion,
                              std::uint32_t alarma,
                              std::uint32_t seguridad) noexcept
{
    if ((alarma == 0U) || (seguridad < alarma))
    {
        return false;
    }

    Configuracion const propuesta{alarma, seguridad};
    configuracion = propuesta;
    return true;
}
}
