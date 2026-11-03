// CH02-E11. Corrección del caso; las pruebas se entregan por separado.
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

struct ResultadoEvaluacion
{
    EstadoMedida estado;
    std::uint16_t valor;
};

class RegistroAdquisicion
{
public:
    void anotar(std::size_t indice, std::uint16_t valor) noexcept
    {
        ultimo_canal_ = indice;
        ultimo_valor_ = valor;
        ++cantidad_registros_;
    }

    std::size_t cantidad_registros() const noexcept
    {
        return cantidad_registros_;
    }

private:
    std::size_t ultimo_canal_{0U};
    std::uint16_t ultimo_valor_{0U};
    std::size_t cantidad_registros_{0U};
};

ResultadoEvaluacion evaluar_canal(Muestras const& muestras,
                                  std::size_t indice,
                                  RegistroAdquisicion& registro) noexcept
{
    if (indice >= muestras.size())
    {
        return {EstadoMedida::canal_invalido, 0U};
    }

    std::uint16_t const lectura{muestras[indice]};
    registro.anotar(indice, lectura);

    if (lectura == 0U)
    {
        return {EstadoMedida::ausente, 0U};
    }

    return {EstadoMedida::valida, lectura};
}
}
