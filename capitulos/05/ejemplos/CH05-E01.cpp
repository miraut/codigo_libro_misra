// CH05-E01. Lectura de una variable que solo se escribe en una rama.
#include <cstdint>

namespace primera_lectura {
std::uint16_t calcular_miliamperios(bool conversion_completa,
                                   std::uint16_t dato_crudo) noexcept
{
    std::uint16_t medida;

    if (conversion_completa)
    {
        medida = dato_crudo;
    }

    return medida; // Riesgo: lectura sin valor si conversion_completa es false.
}
} // namespace primera_lectura
