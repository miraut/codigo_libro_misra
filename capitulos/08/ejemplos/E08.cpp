// CH08-E08. Recursión utilizada solo en evaluación constante.
#include <cstdint>

constexpr std::uint32_t suma_en_compilacion(std::uint32_t cantidad)
{
    return (cantidad == 0U)
        ? 0U
        : cantidad + suma_en_compilacion(cantidad - 1U);
}

static_assert(suma_en_compilacion(6U) == 21U,
              "La suma de los seis primeros enteros es 21");
