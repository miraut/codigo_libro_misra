// CH13-E12. La precedencia cambia el cálculo previsto.
#include <cstdint>

#define ESCALAR_MEDIDA(valor) valor * 2U

namespace supervision
{
inline constexpr std::uint32_t calculo_con_macro{ESCALAR_MEDIDA(2U + 3U)};
// Expansión: 2U + 3U * 2U; resultado: 8.

constexpr std::uint32_t escalar_medida(std::uint32_t valor) noexcept
{
    return valor * 2U;
}

inline constexpr std::uint32_t calculo_con_funcion{escalar_medida(2U + 3U)};
// Resultado: 10.
}
