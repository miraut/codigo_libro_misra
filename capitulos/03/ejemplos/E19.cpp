// CH03-E19. Un alias forma parte de la información de la interfaz.
#include <cstdint>

namespace supervision
{
using IdCanal = std::uint16_t;

std::uint32_t identificador_ampliado(IdCanal canal) noexcept;

std::uint32_t identificador_ampliado(IdCanal canal) noexcept
{
    return static_cast<std::uint32_t>(canal);
}
}
