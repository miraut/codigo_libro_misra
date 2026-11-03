// CH11-E11. El propietario del rango permanece vivo durante el recorrido.
#include <array>
#include <cstdint>

namespace ejemplo_rango_seguro
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
    LoteMuestras const lote{obtener_lote()};
    std::uint32_t suma{0U};

    for (std::uint32_t muestra : lote.consultar_muestras())
    {
        suma += muestra;
    }

    return suma;
}
}
