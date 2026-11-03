// CH11-E01. Ejemplo introductorio, deliberadamente problemático.
#include <cstdint>

namespace ejemplo_alarma_inicial
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
        estado.solicitar_parada = true;
        estado.diagnostico_actualizado = true;
}
}
