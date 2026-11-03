// CH04-E20. Un estrechamiento no queda justificado por la sintaxis del cast.
#include <cstdint>
#include <limits>
#include <optional>

namespace tipos_de_cast
{
std::uint16_t estrechamiento_legado(std::uint32_t lectura) noexcept
{
    return (std::uint16_t)lectura;  // Deliberadamente contrario a Rule 8.2.2.
}

std::optional<std::uint16_t> estrechamiento_verificado(
    std::uint32_t lectura) noexcept
{
    if (lectura > static_cast<std::uint32_t>(
                      std::numeric_limits<std::uint16_t>::max()))
    {
        return std::nullopt;
    }
    return static_cast<std::uint16_t>(lectura);
}
}
