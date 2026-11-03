// CH04-E11. Ensanchar antes de desplazar y validar la posición variable.
#include <cstdint>
#include <optional>

namespace mascaras
{
std::uint32_t extraer(std::uint8_t octeto) noexcept
{
    return static_cast<std::uint32_t>(octeto) << 8U;
}

std::optional<std::uint32_t> bandera(std::uint32_t posicion) noexcept
{
    if (posicion >= 32U)
    {
        return std::nullopt;
    }
    return std::uint32_t{1U} << posicion;
}
}
