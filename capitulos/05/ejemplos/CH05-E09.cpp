// CH05-E09. Una mascara debe comprobarse antes de comparar el resultado.
#include <cstdint>

namespace mascaras {
constexpr std::uint32_t BIT_ERROR{0x08U};

bool error_presente(std::uint32_t estado) noexcept
{
    return (estado & BIT_ERROR) == BIT_ERROR;
}

bool expresion_enganosa(std::uint32_t estado) noexcept
{
    // Equivale a estado & (BIT_ERROR == BIT_ERROR): no comprueba el bit 3.
    return (estado & (BIT_ERROR == BIT_ERROR)) != 0U;
}
} // namespace mascaras
