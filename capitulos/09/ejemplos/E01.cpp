// CH09-E01. Problemático: la llamada no selecciona el miembro heredado.
#include <cstdint>

namespace ejemplo_busqueda
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
        return factor_conversion(); // Encuentra la función libre.
    }
};
}
