// CH13-E13. Decodificación explícita de dos octetos de un mensaje.
#include <array>
#include <cstdint>

namespace protocolo
{
constexpr std::uint16_t leer_entero_be(
    std::array<std::uint8_t, 2U> const& trama) noexcept
{
    std::uint32_t const octeto_alto{trama[0]};
    std::uint32_t const octeto_bajo{trama[1]};
    return static_cast<std::uint16_t>((octeto_alto << 8U) | octeto_bajo);
}
}
