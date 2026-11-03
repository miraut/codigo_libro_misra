// CH14-E09. Conversión decimal con resultado tipado y rango de aplicación.
#include <charconv>
#include <cstdint>
#include <string_view>
#include <system_error>

namespace configuracion
{
enum class EstadoConversion
{
    correcto,
    formato_invalido,
    fuera_de_rango,
    valor_no_permitido
};

struct ResultadoPeriodo
{
    EstadoConversion estado{EstadoConversion::formato_invalido};
    std::uint32_t periodo_ms{0U};
};

ResultadoPeriodo leer_periodo(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return {};
    }

    std::uint32_t valor{0U};
    char const* const inicio = texto.data();
    char const* const final = inicio + texto.size();
    auto const conversion = std::from_chars(inicio, final, valor, 10);

    if (conversion.ec == std::errc::result_out_of_range)
    {
        return {EstadoConversion::fuera_de_rango, 0U};
    }
    if ((conversion.ec != std::errc{}) || (conversion.ptr != final))
    {
        return {EstadoConversion::formato_invalido, 0U};
    }
    if ((valor < 5U) || (valor > 1000U))
    {
        return {EstadoConversion::valor_no_permitido, 0U};
    }
    return {EstadoConversion::correcto, valor};
}
}
