// CH15-E05. El contador sobre la secuencia depende de un contrato ajeno.
#include <cstddef>
#include <cstdint>

extern bool leer_paquete(std::size_t& longitud) noexcept;

bool aceptar_paquete(std::size_t capacidad) noexcept
{
    std::size_t longitud{0U};
    if (!leer_paquete(longitud))
    {
        return false;
    }
    return longitud <= capacidad;
}
