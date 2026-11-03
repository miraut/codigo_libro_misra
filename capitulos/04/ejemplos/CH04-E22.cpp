// CH04-E22. Observación de representación y conversión de dirección.
#include <cstddef>
#include <cstdint>

namespace representacion
{
std::byte primer_byte(std::uint32_t const& valor) noexcept
{
    auto const* bytes = reinterpret_cast<std::byte const*>(&valor);
    return bytes[0];  // Su valor depende de la representación en la plataforma.
}

std::uintptr_t direccion_numerica(std::uint32_t const* valor) noexcept
{
    return reinterpret_cast<std::uintptr_t>(valor);
}
}
