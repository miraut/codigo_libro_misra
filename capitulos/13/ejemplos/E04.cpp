// CH13-E04. Una constante y una función expresadas como entidades de C++17.
#include <cstdint>

namespace configuracion
{
inline constexpr std::uint32_t periodo_muestreo_ms{20U};

constexpr bool muestra_fuera_de_rango(std::uint32_t valor,
                                     std::uint32_t limite) noexcept
{
    return valor > limite;
}
}
