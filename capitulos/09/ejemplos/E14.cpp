// CH09-E14. Caso integrador: conversión exacta y acumulación saturada.
#include <cstdint>
#include <limits>
#include <optional>

namespace conversiones
{
struct PerfilDirecto {};
struct PerfilMultiplicado {};

template<typename Perfil>
struct PoliticaEscala
{
    static constexpr std::uint32_t factor() noexcept
    {
        return 1U;
    }
};

template<>
struct PoliticaEscala<PerfilMultiplicado>
{
    static constexpr std::uint32_t factor() noexcept
    {
        return 4U;
    }
};

class Cuenta
{
public:
    explicit Cuenta(std::uint32_t valor) noexcept : valor_{valor} {}

    std::uint32_t valor() const noexcept
    {
        return valor_;
    }

    friend Cuenta operator+(Cuenta izquierda, Cuenta derecha) noexcept
    {
        auto const maximo = std::numeric_limits<std::uint32_t>::max();
        if (izquierda.valor_ > maximo - derecha.valor_)
        {
            return Cuenta{maximo};
        }
        return Cuenta{izquierda.valor_ + derecha.valor_};
    }

private:
    std::uint32_t valor_;
};

template<typename Perfil>
class Conversor : private PoliticaEscala<Perfil>
{
public:
    std::optional<Cuenta> convertir(std::uint32_t lectura) const noexcept
    {
        auto const multiplicador = this->factor();
        auto const maximo = std::numeric_limits<std::uint32_t>::max();
        if ((multiplicador == 0U) || (lectura > maximo / multiplicador))
        {
            return std::nullopt;
        }
        return Cuenta{lectura * multiplicador};
    }
};

std::optional<Cuenta> acumular_lecturas(std::uint32_t lectura_directa,
                                      std::uint32_t lectura_multiplicada) noexcept
{
    Conversor<PerfilDirecto> const conversor_directo{};
    Conversor<PerfilMultiplicado> const conversor_multiplicado{};

    auto const primera = conversor_directo.convertir(lectura_directa);
    auto const segunda = conversor_multiplicado.convertir(lectura_multiplicada);

    if (!primera.has_value() || !segunda.has_value())
    {
        return std::nullopt;
    }
    return *primera + *segunda;
}
}
