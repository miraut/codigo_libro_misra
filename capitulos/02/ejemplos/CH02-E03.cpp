// CH02-E03. Lectura total: la interfaz responde para cualquier size_t.
#include <array>
#include <cstddef>
#include <cstdint>

namespace supervision
{
using Muestras = std::array<std::uint16_t, 4>;

struct ResultadoLectura
{
    bool correcta;
    std::uint16_t valor;
};

ResultadoLectura leer_canal(Muestras const& muestras,
                            std::size_t indice) noexcept
{
    if (indice >= muestras.size())
    {
        return {false, 0U};
    }
    return {true, muestras[indice]};
}
}
