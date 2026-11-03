#include "control.hpp"

namespace control
{
Resultado evaluar(PuertoAdquisicion& fuente,
                  std::uint16_t umbral) noexcept
{
    if ((umbral == 0U) || (umbral > valor_maximo))
    {
        return { Estado::configuracion_invalida, 0U };
    }

    std::uint32_t dato { 0U };
    if (!fuente.obtener(dato))
    {
        return { Estado::fuente_no_disponible, 0U };
    }

    if (dato > valor_maximo)
    {
        return { Estado::muestra_fuera_de_rango, 0U };
    }

    auto const valor = static_cast<std::uint16_t>(dato);
    if (valor >= umbral)
    {
        return { Estado::alarma, valor };
    }
    return { Estado::normal, valor };
}
}
