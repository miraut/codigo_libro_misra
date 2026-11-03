// CH06-E03. Composicion de valores: no hacen falta miembros especiales propios.
#include <array>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace regla_cero {
struct TablaCalibracion {
    std::array<std::uint16_t, 4U> referencias{};
    std::uint16_t revision{0U};
};

// Una copia puede construirse a partir de un rvalue sin definir un move propio.
struct CopiaDesdeRvalue {
    CopiaDesdeRvalue() = default;
    CopiaDesdeRvalue(CopiaDesdeRvalue const&) = default;
};
static_assert(std::is_move_constructible<CopiaDesdeRvalue>::value,
              "Un constructor de copia const& acepta rvalues");

static_assert(std::is_copy_constructible<TablaCalibracion>::value, "Copiable");
static_assert(std::is_move_constructible<TablaCalibracion>::value, "Construible desde rvalue");

TablaCalibracion duplicar(TablaCalibracion const& original) {
    return original;
}
} // namespace regla_cero
