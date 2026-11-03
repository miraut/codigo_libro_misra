// CH13-E10. Identidad tipada de un evento, sin concatenación de tokens.
#include <cstdint>

namespace diagnostico
{
enum class Evento : std::uint8_t
{
    inicio = 1U,
    fallo_lectura = 2U,
    falta_de_datos = 3U
};

constexpr char const* describir(Evento evento) noexcept
{
    switch (evento)
    {
        case Evento::inicio:
        {
            return "Inicio del equipo";
        }
        case Evento::fallo_lectura:
        {
            return "Fallo de lectura";
        }
        case Evento::falta_de_datos:
        {
            return "No hay datos disponibles";
        }
        default:
        {
            return "Evento desconocido";
        }
    }
}
}
