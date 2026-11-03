// CH05-E10. Los argumentos no tienen un orden relativo garantizado en C++17.
#include <cstdint>

namespace argumentos {
struct Contador {
    std::uint32_t valor{0U};

    std::uint32_t siguiente() noexcept
    {
        ++valor;
        return valor;
    }
};

std::uint32_t combinar(std::uint32_t primero,
                      std::uint32_t segundo) noexcept
{
    return (primero * 10U) + segundo;
}

std::uint32_t sin_orden_acordado(Contador& origen) noexcept
{
    // En C++17 ambas llamadas se completan, pero no hay orden garantizado.
    return combinar(origen.siguiente(), origen.siguiente());
}

std::uint32_t con_orden_explicito(Contador& origen) noexcept
{
    std::uint32_t const primero{origen.siguiente()};
    std::uint32_t const segundo{origen.siguiente()};
    return combinar(primero, segundo);
}
} // namespace argumentos
