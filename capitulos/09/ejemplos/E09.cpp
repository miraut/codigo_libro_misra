// CH09-E09. Las funciones entregan bool y se conserva el cortocircuito.
#include <cstdint>

namespace ejemplo_logico_corregido
{
bool comprobar_autorizacion() noexcept
{
    return false;
}

bool registrar_intento(std::uint32_t& intentos) noexcept
{
    ++intentos;
    return true;
}

bool ejecutar(std::uint32_t& intentos) noexcept
{
    return comprobar_autorizacion() && registrar_intento(intentos);
}
}
