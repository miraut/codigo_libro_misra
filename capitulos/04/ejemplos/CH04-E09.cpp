// CH04-E09. La verificación de rango precede al estrechamiento.
#include <cstdint>
#include <limits>
#include <optional>

namespace asignaciones
{
std::uint32_t ampliar(std::uint16_t dato) noexcept
{
    std::uint32_t const resultado{dato};
    return resultado;
}

std::optional<std::uint16_t> estrechar(std::uint32_t dato) noexcept
{
    if (dato > static_cast<std::uint32_t>(
                   std::numeric_limits<std::uint16_t>::max()))
    {
        return std::nullopt;
    }
    return static_cast<std::uint16_t>(dato);
}
}
