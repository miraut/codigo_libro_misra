// CH13-E03. Alternativa con tipos y evaluación única del argumento.
#include <cstdint>

namespace supervision
{
constexpr std::uint32_t duplicar_lectura(std::uint32_t valor) noexcept
{
    return valor + valor;
}

std::uint32_t siguiente_lectura(std::uint32_t& contador) noexcept
{
    ++contador;
    return contador;
}

std::uint32_t lectura_duplicada(std::uint32_t& contador) noexcept
{
    return duplicar_lectura(siguiente_lectura(contador));
}
}
