// CH14-E17. Uso problemático: clasificación de un char potencialmente negativo.
#include <cctype>

namespace protocolo
{
bool contiene_digito(char caracter)
{
    return std::isdigit(caracter) != 0;
}
}
