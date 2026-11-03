// CH04-E25. El nombre del objeto determina el alcance del bloqueo.
#include <cstdint>
#include <mutex>

namespace bloqueo
{
class Contador
{
public:
    void sumar_incorrectamente()
    {
        std::scoped_lock<std::mutex>{proteccion_};
        // Temporal destruido: la operación siguiente ya no está protegida.
        ++valor_;
    }

    void sumar()
    {
        std::scoped_lock<std::mutex> guardia{proteccion_};
        ++valor_;
    }

private:
    std::mutex proteccion_;
    std::uint32_t valor_{0U};
};
}
