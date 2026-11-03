// CH05-E16. El resultado de una asignacion empleado como condicion.
#include <cstdint>

namespace asignacion_condicional {
std::uint16_t leer_codigo(bool alarma) noexcept
{
    return alarma ? 15U : 0U;
}

bool version_compacta(bool alarma) noexcept
{
    std::uint16_t codigo{0U};
    if ((codigo = leer_codigo(alarma)) != 0U) // Rule 8.18.2: Advisory.
    {
        return true;
    }
    return false;
}

bool version_explicita(bool alarma) noexcept
{
    std::uint16_t const codigo = leer_codigo(alarma);
    return codigo != 0U;
}
} // namespace asignacion_condicional
