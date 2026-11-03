// CH01-E05. Orden no especificado de evaluación de argumentos.
#include <cstdint>

namespace adquisicion
{
std::uint32_t siguiente_identificador(std::uint32_t& contador) noexcept
{
    ++contador;
    return contador;
}

std::uint32_t combinar(std::uint32_t primero, std::uint32_t segundo) noexcept
{
    return (primero * 10U) + segundo;
}

std::uint32_t construir_codigo() noexcept
{
    std::uint32_t contador{0U};
    return combinar(siguiente_identificador(contador),
                    siguiente_identificador(contador));
}
}

namespace adquisicion
{
std::uint32_t construir_codigo_ordenado() noexcept
{
    std::uint32_t contador{0U};
    std::uint32_t const primero{siguiente_identificador(contador)};
    std::uint32_t const segundo{siguiente_identificador(contador)};
    return combinar(primero, segundo);
}
}

