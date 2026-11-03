// CH04-E02. La conversión expresa una condición ya verificada.
#include <cstdint>
#include <limits>
#include <optional>

namespace conversion_validada
{
std::optional<std::uint32_t> corregir(std::uint32_t pulsos,
                                     std::int32_t ajuste) noexcept
{
    std::int64_t const amplio =
        static_cast<std::int64_t>(pulsos) +
        static_cast<std::int64_t>(ajuste);

    if ((amplio < 0) ||
        (amplio > static_cast<std::int64_t>(
                       std::numeric_limits<std::uint32_t>::max())))
    {
        return std::nullopt;
    }
    return static_cast<std::uint32_t>(amplio);
}
}
