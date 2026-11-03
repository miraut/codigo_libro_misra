// CH12-E02. La llamada permite dos asignaciones distintas a los argumentos.
#include <cstdint>

namespace ejemplo_argumentos
{
struct Resultado
{
    std::uint32_t primero;
    std::uint32_t segundo;
};

std::uint32_t siguiente(std::uint32_t& contador) noexcept
{
    ++contador;
    return contador;
}

Resultado registrar(std::uint32_t primero,
                    std::uint32_t segundo) noexcept
{
    return Resultado{primero, segundo};
}

Resultado construir_ambiguo() noexcept
{
    std::uint32_t contador{0U};
    return registrar(siguiente(contador), siguiente(contador));
}

Resultado construir_ordenado() noexcept
{
    std::uint32_t contador{0U};
    std::uint32_t const primera_lectura{siguiente(contador)};
    std::uint32_t const segunda_lectura{siguiente(contador)};
    return registrar(primera_lectura, segunda_lectura);
}
}
