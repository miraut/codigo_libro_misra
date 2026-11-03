// CH12-E09. Transferencia de una posición: exactamente un productor y un consumidor.
#include <atomic>
#include <cstdint>

namespace ejemplo_canal_spsc
{
struct Muestra
{
    std::uint32_t secuencia{0U};
    std::uint32_t valor{0U};
};

class CanalUnaPosicion
{
public:
    bool publicar(Muestra const& nueva_muestra) noexcept
    {
        if (ocupada_.load(std::memory_order_acquire))
        {
            return false;
        }

        muestra_ = nueva_muestra;
        ocupada_.store(true, std::memory_order_release);
        return true;
    }

    bool retirar(Muestra& destino) noexcept
    {
        if (!ocupada_.load(std::memory_order_acquire))
        {
            return false;
        }

        destino = muestra_;
        ocupada_.store(false, std::memory_order_release);
        return true;
    }

private:
    Muestra muestra_{};
    std::atomic<bool> ocupada_{false};
};
}
