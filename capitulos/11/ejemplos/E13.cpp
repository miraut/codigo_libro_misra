// CH11-E13. Se conserva una copia del array antes de destruirse el temporal.
#include <array>
#include <cstdint>

namespace ejemplo_copia_de_rango
{
struct LoteMuestras
{
    std::array<std::uint32_t, 3U> muestras{{2U, 3U, 4U}};

    std::array<std::uint32_t, 3U> const& consultar_muestras() const noexcept
    {
        return muestras;
    }
};

LoteMuestras obtener_lote() noexcept
{
    return LoteMuestras{};
}

std::uint32_t sumar_muestras() noexcept
{
    auto const muestras = obtener_lote().consultar_muestras();
    std::uint32_t suma{0U};

    for (std::uint32_t muestra : muestras)
    {
        suma += muestra;
    }

    return suma;
}
}
