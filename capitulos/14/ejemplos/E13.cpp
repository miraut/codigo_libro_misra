// CH14-E13. Interfaz de operaciones permitidas, con resultados definidos.
#include <cstdint>

namespace mantenimiento
{
enum class Accion
{
    consultar_estado,
    solicitar_reinicio
};

enum class Resultado
{
    aceptada,
    no_disponible
};

Resultado tramitar(Accion accion, bool reinicio_habilitado) noexcept
{
    switch (accion)
    {
        case Accion::consultar_estado:
        {
            return Resultado::aceptada;
        }
        case Accion::solicitar_reinicio:
        {
            return reinicio_habilitado
                ? Resultado::aceptada : Resultado::no_disponible;
        }
        default:
        {
            return Resultado::no_disponible;
        }
    }
}
}
