// CH12-E10. Señalización entre tareas, pendiente de integración con la plataforma.
#include <atomic>

namespace ejemplo_aviso
{
class AvisoAdquisicion
{
public:
    void notificar_desde_tarea() noexcept
    {
        pendiente_.store(true, std::memory_order_release);
    }

    bool retirar_aviso() noexcept
    {
        return pendiente_.exchange(false, std::memory_order_acq_rel);
    }

private:
    std::atomic<bool> pendiente_{false};
};
}
