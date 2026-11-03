// CH08-E05. Cada ruta entrega un estado con significado.
#include <cstdint>

enum class EstadoEnlace : std::uint8_t
{
    disponible,
    saturado,
    sin_respuesta
};

EstadoEnlace evaluar_enlace(bool hay_respuesta,
                           std::uint32_t ocupacion) noexcept
{
    if (!hay_respuesta)
    {
        return EstadoEnlace::sin_respuesta;
    }

    if (ocupacion >= 90U)
    {
        return EstadoEnlace::saturado;
    }

    return EstadoEnlace::disponible;
}
