// CH07-E01. Problemático. No utilizar el resultado.
#include <cstdint>

namespace adquisicion
{
struct Lectura
{
    std::uint32_t secuencia;
    std::uint32_t valor;
};

Lectura const* preparar_lectura(std::uint32_t valor) noexcept
{
    Lectura resultado{17U, valor};
    return &resultado;
}
}
