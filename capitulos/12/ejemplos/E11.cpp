// CH12-E11. Conversión numérica de formato fijo sin estado regional global.
#include <charconv>
#include <cstdint>
#include <optional>
#include <string_view>
#include <system_error>

namespace ejemplo_conversion
{
std::optional<std::int32_t> leer_decimal(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return std::nullopt;
    }

    std::int32_t numero{0};
    char const* const fin{texto.data() + texto.size()};
    std::from_chars_result const resultado{
        std::from_chars(texto.data(), fin, numero, 10)};

    if ((resultado.ec != std::errc{}) || (resultado.ptr != fin))
    {
        return std::nullopt;
    }

    return numero;
}
}
