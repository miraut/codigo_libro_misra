// CH15-E07. Riesgo: volatile no sincroniza dos hilos en C++17.
// Se compila, pero no debe ejecutarse en paralelo como codigo seguro.
#include <cstdint>

struct EstadoCompartido
{
    volatile bool listo{false};
    std::uint32_t medida{0U};
};

void publicar_sin_sincronizar(EstadoCompartido& estado,
                             std::uint32_t nueva_medida) noexcept
{
    estado.medida = nueva_medida;
    estado.listo = true;
}
