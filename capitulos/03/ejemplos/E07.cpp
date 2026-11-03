// CH03-E07. Dos grafías, dos valores.
#include <cstdint>

namespace supervision
{
constexpr std::uint32_t alarma_decimal{52U};
constexpr std::uint32_t alarma_octal_accidental{052}; // Deliberadamente no conforme.

static_assert(alarma_decimal == 52U, "El identificador pretendido es 52");
static_assert(alarma_octal_accidental == 42U,
              "052 representa cuarenta y dos, no cincuenta y dos");
}
