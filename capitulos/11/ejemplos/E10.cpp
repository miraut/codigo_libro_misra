// CH11-E10. Problemático en C++17: referencia a un subobjeto de un temporal.
#include <array>
#include <cstdint>

namespace ejemplo_rango_colgante
{
class LoteMuestras
{
public:
    std::array<std::uint32_t, 3U> const& consultar_muestras() const noexcept
    {
        return muestras_;
    }

private:
    std::array<std::uint32_t, 3U> muestras_{{10U, 20U, 30U}};
};

LoteMuestras obtener_lote() noexcept
{
    return LoteMuestras{};
}

std::uint32_t sumar_muestras() noexcept
{
    std::uint32_t suma{0U};
    for (std::uint32_t muestra : obtener_lote().consultar_muestras())
    {
        suma += muestra; // En C++17, se accede a un rango cuya vida ha terminado.
    }
    return suma;
}
}
