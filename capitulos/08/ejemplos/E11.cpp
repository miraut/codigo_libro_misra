// CH08-E11. Problemático: std::move no elimina const.
#include <cstdint>
#include <utility>
#include <vector>

std::vector<std::uint32_t> duplicar_lecturas(
    std::vector<std::uint32_t> const& lecturas)
{
    std::vector<std::uint32_t> copia{std::move(lecturas)};
    return copia;
}
