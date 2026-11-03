// CH09-E07. Una política se selecciona mediante una clase especializada.
#include <cstdint>

namespace ejemplo_politicas
{
struct PerfilGeneral {};
struct PerfilAltaResolucion {};

template<typename Perfil>
struct LimiteAdmitido
{
    static constexpr std::uint32_t valor{1000U};
};

template<>
struct LimiteAdmitido<PerfilAltaResolucion>
{
    static constexpr std::uint32_t valor{8000U};
};

template<typename Perfil>
bool admitir(std::uint32_t lectura) noexcept
{
    return lectura <= LimiteAdmitido<Perfil>::valor;
}
}
