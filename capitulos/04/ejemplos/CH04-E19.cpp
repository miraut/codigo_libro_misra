// CH04-E19. Alternativas tipadas, sin reinterpretar memoria como otro objeto.
#include <cstdint>
#include <variant>

namespace alternativas
{
enum class Error : std::uint8_t { formato = 1U, fuera_de_rango = 2U };
using Resultado = std::variant<std::uint16_t, Error>;

Resultado analizar(bool dato_valido, std::uint16_t lectura)
{
    if (!dato_valido)
    {
        return Error::formato;
    }
    return lectura;
}

bool contiene_medida(Resultado const& resultado) noexcept
{
    return std::holds_alternative<std::uint16_t>(resultado);
}
}
