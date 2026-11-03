// CH04-E07. Dos etapas: promoción y asignación al destino.
#include <cstdint>
#include <type_traits>

namespace promociones
{
static_assert(std::is_same_v<
                  decltype(std::uint8_t{2U} + std::uint8_t{3U}), int>,
              "Los octetos se promocionan a int en esta plataforma");

std::uint32_t sumar_octetos(std::uint8_t primero,
                           std::uint8_t segundo) noexcept
{
    return static_cast<std::uint32_t>(primero) +
           static_cast<std::uint32_t>(segundo);
}
}
