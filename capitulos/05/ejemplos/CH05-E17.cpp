// CH05-E17. Inicializacion local al if y condicion independiente.
#include <cstdint>

namespace decision_local {
std::uint16_t obtener_estado(bool periferico_listo) noexcept
{
    return periferico_listo ? 7U : 0U;
}

bool periferico_preparado(bool periferico_listo) noexcept
{
    if (std::uint16_t const estado = obtener_estado(periferico_listo);
        estado != 0U)
    {
        return true;
    }
    return false;
}
} // namespace decision_local
