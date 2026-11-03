// CH15-E08. Esquema de una sola publicacion con release/acquire.
// El protocolo de multiples ciclos necesita una disciplina adicional.
#include <atomic>
#include <cstdint>

struct PublicacionUnica
{
    std::uint32_t medida{0U};
    std::atomic<bool> disponible{false};
};

void publicar(PublicacionUnica& estado, std::uint32_t dato) noexcept
{
    estado.medida = dato;
    estado.disponible.store(true, std::memory_order_release);
}

bool consumir(PublicacionUnica const& estado, std::uint32_t& salida) noexcept
{
    if (!estado.disponible.load(std::memory_order_acquire))
    {
        return false;
    }
    salida = estado.medida;
    return true;
}
