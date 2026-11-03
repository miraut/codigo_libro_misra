#include "proveedor_simulado.hpp"

// Código inventado: se compila como biblioteca estática para reproducibilidad.
extern "C" bool cots_obtener_medida(std::uint32_t* destino) noexcept
{
    if (destino == nullptr)
    {
        return false;
    }
    *destino = 3500U;
    return true;
}
