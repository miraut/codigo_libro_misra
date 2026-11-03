// CH07-E02. Alternativa por valor.
#include <cstdint>

namespace adquisicion
{
struct Lectura
{
    std::uint32_t secuencia;
    std::uint32_t valor;
};

Lectura preparar_lectura(std::uint32_t valor) noexcept
{
    return Lectura{17U, valor};
}
}
