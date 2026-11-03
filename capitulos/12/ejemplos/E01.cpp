// CH12-E01. Compartir dos valores volatile no establece sincronización.
#include <cstdint>

namespace ejemplo_estado_compartido
{
struct DatosCompartidos
{
    volatile std::uint32_t ultima_medida{0U};
    volatile bool nueva_medida{false};
};

void recibir_medida(DatosCompartidos& datos,
                    std::uint32_t medida) noexcept
{
    datos.ultima_medida = medida;
    datos.nueva_medida = true;
}

bool obtener_medida(DatosCompartidos& datos,
                    std::uint32_t& medida) noexcept
{
    if (datos.nueva_medida)
    {
        medida = datos.ultima_medida;
        datos.nueva_medida = false;
        return true;
    }

    return false;
}
}
