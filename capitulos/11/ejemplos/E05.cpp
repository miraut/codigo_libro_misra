// CH11-E05. Problemático: la ejecución continúa en el case siguiente.
#include <cstdint>

namespace ejemplo_switch_incompleto
{
enum class Modo : std::uint8_t { diagnostico, normal, detenido };

struct Indicadores
{
    bool incidencia{false};
    bool disponible{false};
};

void actualizar_indicadores(Modo modo, Indicadores& indicadores) noexcept
{
    switch (modo)
    {
        case Modo::diagnostico:
            indicadores.incidencia = true;
        case Modo::normal:
            indicadores.disponible = true;
            break;
        case Modo::detenido:
            indicadores.disponible = false;
            break;
        default:
            indicadores.incidencia = true;
            break;
    }
}
}
