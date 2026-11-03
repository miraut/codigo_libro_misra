// CH12-E08. Contador atómico sin protocolo adicional de publicación.
#include <atomic>
#include <cstdint>

namespace ejemplo_contador_atomico
{
class ContadorEventos
{
public:
    void registrar_evento() noexcept
    {
        (void)contador_.fetch_add(1U, std::memory_order_relaxed);
    }

    std::uint32_t consultar() const noexcept
    {
        return contador_.load(std::memory_order_relaxed);
    }

private:
    std::atomic<std::uint32_t> contador_{0U};
};
}
