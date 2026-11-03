// CH09-E02. La dependencia de la base queda expresada en la llamada.
#include <cstdint>

namespace ejemplo_dependencia
{
std::uint32_t factor_conversion() noexcept
{
    return 100U;
}

struct PerfilTermico
{
    static constexpr std::uint32_t escala{2U};
};

template<typename Perfil>
class PoliticaConversion
{
protected:
    std::uint32_t factor_conversion() const noexcept
    {
        return Perfil::escala;
    }
};

template<typename Perfil>
class Conversor : private PoliticaConversion<Perfil>
{
public:
    std::uint32_t consultar_factor() const noexcept
    {
        return this->factor_conversion();
    }
};
}
