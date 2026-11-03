// CH09-E12. Problemático para Rule 16.6.1: operador binario miembro.
#include <cstdint>
#include <limits>

namespace ejemplo_operador_miembro
{
class CantidadPulsos
{
public:
    explicit CantidadPulsos(std::uint32_t valor) noexcept : valor_{valor} {}

    CantidadPulsos operator*(std::uint32_t factor) const noexcept
    {
        auto const maximo = std::numeric_limits<std::uint32_t>::max();
        if ((factor != 0U) && (valor_ > maximo / factor))
        {
            return CantidadPulsos{maximo};
        }
        return CantidadPulsos{valor_ * factor};
    }

    std::uint32_t valor() const noexcept
    {
        return valor_;
    }

private:
    std::uint32_t valor_;
};

std::uint32_t demostrar() noexcept
{
    CantidadPulsos const lectura{12U};
    return (lectura * 3U).valor();
    // La forma 3U * lectura no encuentra este operador miembro.
}
}
