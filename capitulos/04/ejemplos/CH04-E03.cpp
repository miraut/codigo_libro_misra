// CH04-E03. Dos conceptos que comparten representación, pero no operaciones.
#include <cstdint>

namespace dominio
{
class NumeroPulsos
{
public:
    explicit constexpr NumeroPulsos(std::uint32_t valor) noexcept
        : valor_{valor} {}

    constexpr std::uint32_t valor() const noexcept { return valor_; }

private:
    std::uint32_t valor_;
};

class Canal
{
public:
    explicit constexpr Canal(std::uint32_t identificador) noexcept
        : identificador_{identificador} {}

    constexpr std::uint32_t identificador() const noexcept
    {
        return identificador_;
    }

private:
    std::uint32_t identificador_;
};

constexpr bool pertenece(NumeroPulsos medida, Canal origen) noexcept
{
    return (medida.valor() > 0U) && (origen.identificador() < 8U);
}
}
