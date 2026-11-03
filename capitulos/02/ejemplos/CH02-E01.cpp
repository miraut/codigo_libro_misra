// CH02-E01. Código deliberadamente problemático; no ejecutar con indice == 4.
#include <array>
#include <cstddef>
#include <cstdint>

namespace supervision
{
using Muestras = std::array<std::uint16_t, 4>;

enum class EstadoMedida
{
    valida,
    ausente,
    canal_invalido
};

void anotar_adquisicion() noexcept;

EstadoMedida evaluar_canal(Muestras const& muestras,
                           std::size_t indice) noexcept
{
    if (indice > muestras.size())
    {
        return EstadoMedida::canal_invalido;
    }

    std::uint16_t const lectura{muestras[indice]};
    if (lectura == 0U)
    {
        return EstadoMedida::ausente;
    }
    return EstadoMedida::valida;

    anotar_adquisicion(); // Inalcanzable: la función ya ha retornado.
}
}
