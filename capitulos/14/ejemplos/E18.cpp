// CH14-E18. Reconocimiento de dígitos del formato definido por el protocolo.
#include <string_view>

namespace protocolo
{
constexpr bool es_digito_decimal(char caracter) noexcept
{
    return (caracter >= '0') && (caracter <= '9');
}

bool contiene_solo_digitos(std::string_view texto) noexcept
{
    if (texto.empty())
    {
        return false;
    }

    for (char const caracter : texto)
    {
        if (!es_digito_decimal(caracter))
        {
            return false;
        }
    }
    return true;
}
}
