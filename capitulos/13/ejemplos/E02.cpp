// CH13-E02. Uso problemático: la expresión de entrada aparece dos veces.
#include <cstdint>

#define DUPLICAR_LECTURA(valor) ((valor) + (valor))

namespace supervision
{
std::uint32_t siguiente_lectura(std::uint32_t& contador) noexcept
{
    ++contador;
    return contador;
}

std::uint32_t lectura_duplicada(std::uint32_t& contador) noexcept
{
    return DUPLICAR_LECTURA(siguiente_lectura(contador));
}
}
