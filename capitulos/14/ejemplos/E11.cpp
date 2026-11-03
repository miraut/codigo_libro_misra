// CH14-E11. Copia acotada hacia un buffer de caracteres terminado en nulo.
#include <algorithm>
#include <array>
#include <string_view>

namespace diagnostico
{
bool copiar_etiqueta(std::string_view texto,
                     std::array<char, 12U>& destino) noexcept
{
    if (texto.size() >= destino.size())
    {
        return false;
    }

    auto const fin_copia =
        std::copy(texto.begin(), texto.end(), destino.begin());
    *fin_copia = '\0';
    return true;
}
}
