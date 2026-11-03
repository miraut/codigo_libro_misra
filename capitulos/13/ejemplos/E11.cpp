// CH13-E11. Uso mixto: un alias se expande en una posición y en otra no.
#include <cstdint>

#define CANAL_ACTUAL canal_principal
#define SUMAR_AJUSTE(canal) ((canal) + canal##_ajuste)

namespace supervision
{
inline constexpr std::uint32_t canal_principal{20U};
inline constexpr std::uint32_t CANAL_ACTUAL_ajuste{3U};
inline constexpr std::uint32_t canal_principal_ajuste{9U};

inline constexpr std::uint32_t resultado{SUMAR_AJUSTE(CANAL_ACTUAL)};
// El resultado es 23: se suman canal_principal y CANAL_ACTUAL_ajuste.
}
