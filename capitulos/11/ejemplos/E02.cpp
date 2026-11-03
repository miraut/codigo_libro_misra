// CH11-E02. Ambas operaciones pertenecen al mismo camino de ejecución.
#include <cstdint>

namespace ejemplo_alarma_revisada
{
struct EstadoSupervision
{
    bool solicitar_parada{false};
    bool diagnostico_actualizado{false};
};

void comprobar_temperatura(bool lectura_valida,
                          std::uint32_t temperatura,
                          EstadoSupervision& estado) noexcept
{
    if (lectura_valida && (temperatura > 80U))
    {
        estado.solicitar_parada = true;
        estado.diagnostico_actualizado = true;
    }
}
}
