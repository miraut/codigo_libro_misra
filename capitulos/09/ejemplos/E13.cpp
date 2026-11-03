// CH09-E13. Las dos orientaciones se expresan como funciones no miembro.
#include <cstdint>
#include <limits>

namespace ejemplo_operadores_libres
{
class CantidadPulsos
{
public:
    explicit CantidadPulsos(std::uint32_t valor) noexcept : valor_{valor} {}

    std::uint32_t valor() const noexcept
    {
        return valor_;
    }

    friend CantidadPulsos operator*(CantidadPulsos lectura,
                                    std::uint32_t factor) noexcept
    {
        auto const maximo = std::numeric_limits<std::uint32_t>::max();
        if ((factor != 0U) && (lectura.valor_ > maximo / factor))
        {
            return CantidadPulsos{maximo};
        }
        return CantidadPulsos{lectura.valor_ * factor};
    }

    friend CantidadPulsos operator*(std::uint32_t factor,
                                    CantidadPulsos lectura) noexcept
    {
        return lectura * factor;
    }

private:
    std::uint32_t valor_;
};

bool comprobar_simetria() noexcept
{
    CantidadPulsos const lectura{12U};
    return (lectura * 3U).valor() == (3U * lectura).valor();
}
}
