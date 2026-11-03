// CH10-E13. Conversión entera en C++17 con resultado explícito.
#include <charconv>
#include <cstdint>
#include <optional>
#include <string_view>
#include <system_error>

namespace ejemplo_conversion
{
std::optional<std::uint32_t> interpretar_entero(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return std::nullopt;
    }

    std::uint32_t valor{0U};
    char const* const comienzo = texto.data();
    char const* const fin = comienzo + texto.size();
    auto const conversion = std::from_chars(comienzo, fin, valor);

    if ((conversion.ec != std::errc{}) || (conversion.ptr != fin))
    {
        return std::nullopt;
    }
    return valor;
}
}
