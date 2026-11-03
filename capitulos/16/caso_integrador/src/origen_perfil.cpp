#include "control.hpp"

#if defined(CH16_PERFIL_LABORATORIO) == defined(CH16_PERFIL_EQUIPO)
#error Debe seleccionarse exactamente un perfil
#endif

#if defined(CH16_PERFIL_EQUIPO)
#include "proveedor_simulado.hpp"
#endif

namespace control
{
bool OrigenPerfil::obtener(std::uint32_t& valor) noexcept
{
#if defined(CH16_PERFIL_LABORATORIO)
    valor = 420U;
    return true;
#else
    return proveedor_simulado::obtener_medida(valor);
#endif
}
}
