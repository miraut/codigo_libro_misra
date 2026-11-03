// CH11-E04. Clasificación que deja definido el caso restante.
#include <cstdint>

namespace ejemplo_clasificacion
{
enum class EstadoLectura : std::uint8_t
{
    aceptada,
    no_disponible,
    inconsistente
};

EstadoLectura clasificar_lectura(bool datos_recibidos,
                               bool comprobacion_correcta) noexcept
{
    EstadoLectura estado{EstadoLectura::inconsistente};

    if (datos_recibidos && comprobacion_correcta)
    {
        estado = EstadoLectura::aceptada;
    }
    else if (!datos_recibidos)
    {
        estado = EstadoLectura::no_disponible;
    }
    else
    {
        estado = EstadoLectura::inconsistente;
    }

    return estado;
}
}
