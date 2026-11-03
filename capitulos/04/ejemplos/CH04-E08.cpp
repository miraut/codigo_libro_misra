// CH04-E08. Comparación directa entre la suma modular y la suma validada.
#include <cstdint>
#include <optional>

namespace signo
{
std::uint32_t suma_modular(std::uint32_t lectura,
                          std::int32_t ajuste) noexcept
{
    return lectura + ajuste;  // Riesgo semántico; Rule 7.0.5.
}

std::optional<std::uint32_t> suma_del_dominio(
    std::uint32_t lectura, std::int32_t ajuste) noexcept
{
    std::int64_t const calculo =
        static_cast<std::int64_t>(lectura) +
        static_cast<std::int64_t>(ajuste);

    if ((calculo < 0) || (calculo > 4'294'967'295LL))
    {
        return std::nullopt;
    }
    return static_cast<std::uint32_t>(calculo);
}
}
