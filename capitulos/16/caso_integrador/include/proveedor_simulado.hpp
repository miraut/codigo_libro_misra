#ifndef CH16_PROVEEDOR_SIMULADO_HPP
#define CH16_PROVEEDOR_SIMULADO_HPP
#include <cstdint>

// Contrato C ilustrativo. No constituye evidencia de un COTS real.
extern "C" bool cots_obtener_medida(std::uint32_t* destino) noexcept;

namespace proveedor_simulado
{
inline bool obtener_medida(std::uint32_t& salida) noexcept
{
    return cots_obtener_medida(&salida);
}
}
#endif
