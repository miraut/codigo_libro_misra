// CH04-E06. Comparación de caracteres sin aritmética sobre su codificación.
#include <string>

namespace caracteres
{
bool es_separador(char caracter) noexcept
{
    return std::char_traits<char>::eq(caracter, ';');
}

bool precede(char primero, char segundo) noexcept
{
    return std::char_traits<char>::lt(primero, segundo);
}

std::char_traits<char>::int_type codigo_de(char valor) noexcept
{
    return std::char_traits<char>::to_int_type(valor);
}
}
