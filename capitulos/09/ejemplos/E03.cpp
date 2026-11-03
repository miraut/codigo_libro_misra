// CH09-E03. Tipo dependiente y miembro heredado introducido con using.
#include <cstdint>

namespace ejemplo_declaraciones
{
struct PerfilAdquisicion
{
    static constexpr std::uint32_t limite{4095U};
};

template<typename Perfil>
class ParametrosBase
{
public:
    using TipoLectura = std::uint32_t;

    TipoLectura obtener_limite() const noexcept
    {
        return Perfil::limite;
    }
};

template<typename Perfil>
class Comprobador : private ParametrosBase<Perfil>
{
    using ParametrosBase<Perfil>::obtener_limite;

public:
    using TipoLectura = typename ParametrosBase<Perfil>::TipoLectura;

    bool admitir(TipoLectura lectura) const noexcept
    {
        return lectura <= obtener_limite();
    }
};
}
