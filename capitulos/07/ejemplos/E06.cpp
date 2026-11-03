// CH07-E06. Referencia en lvalue y valor en rvalue.
#include <array>
#include <cstdint>

namespace adquisicion
{
class Ventana
{
public:
    explicit Ventana(std::uint32_t muestra) noexcept
        : registros_{{muestra, 0U, 0U, 0U}}
    {
    }

    std::uint32_t const& primera() const & noexcept
    {
        return registros_[0U];
    }

    std::uint32_t primera() const && noexcept
    {
        return registros_[0U];
    }

private:
    std::array<std::uint32_t, 4U> registros_;
};

std::uint32_t primera_de_una_lectura() noexcept
{
    return Ventana{73U}.primera();
}
}
