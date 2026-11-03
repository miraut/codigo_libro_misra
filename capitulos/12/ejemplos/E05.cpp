// CH12-E05. Contador local persistente, problemático para Rule 6.7.1.
#include <cstdint>

namespace ejemplo_contador_oculto
{
std::uint32_t asignar_numero() noexcept
{
    static std::uint32_t siguiente_numero{0U};
    ++siguiente_numero;
    return siguiente_numero;
}
}
