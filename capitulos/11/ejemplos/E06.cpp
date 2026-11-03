// CH11-E06. Cada rama termina y el caso restante está definido.
#include <cstdint>

namespace ejemplo_switch_revisado
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
            indicadores.disponible = false;
            break;
        case Modo::normal:
            indicadores.incidencia = false;
            indicadores.disponible = true;
            break;
        case Modo::detenido:
            indicadores.disponible = false;
            break;
        default:
            indicadores.incidencia = true;
            indicadores.disponible = false;
            break;
    }
}
}
