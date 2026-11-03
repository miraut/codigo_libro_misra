// CH05-E04. Calculo de una constante con varias ramas legibles.
#include <cstdint>

namespace inicializacion_condicional {
std::uint16_t limite_admisible(bool modo_diagnostico,
                                bool sensor_calibrado) noexcept
{
    std::uint16_t const limite = [=]() noexcept -> std::uint16_t {
        if (!sensor_calibrado)
        {
            return 0U;
        }
        if (modo_diagnostico)
        {
            return 750U;
        }
        return 900U;
    }();

    return limite;
}
} // namespace inicializacion_condicional
