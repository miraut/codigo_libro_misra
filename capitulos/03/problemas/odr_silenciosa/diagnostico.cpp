#include "medidas_diagnostico.hpp"
namespace supervision
{
std::uint32_t leer_identificador(Muestra const& muestra) noexcept
{
    return muestra.identificador;
}
}
