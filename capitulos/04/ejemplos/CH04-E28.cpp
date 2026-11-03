// CH04-E28. Taller: cuatro expresiones independientes para razonar sobre sus tipos.
#include <cstdint>
#include <type_traits>

namespace taller
{
constexpr std::uint8_t octeto{250U};
constexpr std::uint32_t mascara{0x8000'0000U};
constexpr std::int32_t ajuste{-3};

static_assert(std::is_same_v<decltype(octeto + octeto), int>);
static_assert(std::is_same_v<decltype(mascara + ajuste), std::uint32_t>);
static_assert(std::is_same_v<decltype(-octeto), int>);
static_assert(std::is_same_v<decltype(mascara << 1U), std::uint32_t>);
}
