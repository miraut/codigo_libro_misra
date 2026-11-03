// CH05-E18. El operador coma no es el separador de argumentos.
#include <cstdint>

namespace operador_coma {
std::uint32_t incrementar(std::uint32_t& contador) noexcept
{
    ++contador;
    return contador;
}

std::uint32_t calculo_compacto(std::uint32_t& contador) noexcept
{
    return (incrementar(contador), contador + 10U); // Operador coma.
}

std::uint32_t calculo_explicito(std::uint32_t& contador) noexcept
{
    (void)incrementar(contador);
    return contador + 10U;
}

std::uint32_t suma(std::uint32_t a, std::uint32_t b) noexcept
{
    return a + b; // La coma en la firma separa parametros.
}
} // namespace operador_coma
