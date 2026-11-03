// CH01-E04. Capacidad conocida y resultado con longitud explícita.
#include <array>
#include <cstddef>
#include <cstdint>

namespace adquisicion
{
constexpr std::size_t capacidad_muestras{32U};

struct LoteMuestras
{
    bool admitido;
    std::size_t cantidad;
    std::array<std::uint8_t, capacidad_muestras> valores;
};

LoteMuestras preparar_muestras(std::size_t cantidad,
                              std::uint8_t valor_inicial) noexcept
{
    LoteMuestras resultado{false, 0U, {}};
    if (cantidad > capacidad_muestras)
    {
        return resultado;
    }

    for (std::size_t indice{0U}; indice < cantidad; ++indice)
    {
        resultado.valores[indice] = valor_inicial;
    }
    resultado.cantidad = cantidad;
    resultado.admitido = true;
    return resultado;
}
}
