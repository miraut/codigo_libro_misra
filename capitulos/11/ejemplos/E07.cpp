// CH11-E07. Continuación intencionada, identificada en C++17.
#include <cstdint>

namespace ejemplo_caida_controlada
{
enum class EstadoCanal : std::uint8_t { pendiente, activo, desconectado };

struct Estadisticas
{
    std::uint32_t mensajes_pendientes{0U};
    std::uint32_t revisiones_canal{0U};
};

void registrar_estado(EstadoCanal estado, Estadisticas& estadisticas) noexcept
{
    switch (estado)
    {
        case EstadoCanal::pendiente:
            ++estadisticas.mensajes_pendientes;
            [[fallthrough]];
        case EstadoCanal::activo:
            ++estadisticas.revisiones_canal;
            break;
        case EstadoCanal::desconectado:
            break;
        default:
            break;
    }
}
}
