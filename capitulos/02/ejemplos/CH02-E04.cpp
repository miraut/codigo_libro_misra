// CH02-E04. El tipo IndiceCanal solo se obtiene tras validar el rango.
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace supervision
{
using Muestras = std::array<std::uint16_t, 4>;

class IndiceCanal
{
public:
    static std::optional<IndiceCanal> crear(std::size_t candidato) noexcept
    {
        if (candidato >= 4U)
        {
            return std::nullopt;
        }
        return IndiceCanal{candidato};
    }

    std::size_t valor() const noexcept { return indice_; }

private:
    explicit IndiceCanal(std::size_t indice) noexcept : indice_{indice} {}
    std::size_t indice_;
};

std::uint16_t extraer_canal(Muestras const& muestras,
                            IndiceCanal indice) noexcept
{
    return muestras[indice.valor()];
}
}
