// CH08-E07. Cálculo iterativo con profundidad de pila constante.
#include <cstdint>

std::uint32_t sumar_indices(std::uint8_t cantidad) noexcept
{
    std::uint32_t suma{0U};

    for (std::uint32_t indice{1U}; indice <= cantidad; ++indice)
    {
        suma += indice;
    }

    return suma;
}
