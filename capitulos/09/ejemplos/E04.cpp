// CH09-E04. Una llamada genérica encuentra una función por ADL.
#include <cstdint>

namespace dispositivos
{
struct Lectura
{
    std::uint32_t valor;
};

bool es_valida(Lectura lectura) noexcept
{
    return lectura.valor <= 4095U;
}
}

namespace algoritmos
{
template<typename TipoLectura>
bool admitir(TipoLectura const& lectura) noexcept
{
    return es_valida(lectura); // ADL encuentra dispositivos::es_valida.
}
}
