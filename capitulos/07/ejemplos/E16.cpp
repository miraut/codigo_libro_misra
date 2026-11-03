// CH07-E16. Problemático: el registro puede sobrevivir a 'temporal'.
#include <array>
#include <cstdint>

namespace adquisicion
{
struct Trama
{
    std::uint32_t numero{0U};
    std::array<std::uint8_t, 8U> datos{};
};

class RegistroDiferido
{
public:
    void guardar(Trama const* trama) noexcept
    {
        pendiente_ = trama;
    }

private:
    Trama const* pendiente_{nullptr};
};

void adquirir(RegistroDiferido& registro) noexcept
{
    Trama temporal{};
    temporal.numero = 1U;
    registro.guardar(&temporal);
}
}
