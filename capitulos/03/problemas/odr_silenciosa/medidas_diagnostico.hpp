#ifndef SUPERVISION_MEDIDAS_DIAGNOSTICO_HPP
#define SUPERVISION_MEDIDAS_DIAGNOSTICO_HPP
#include <cstdint>
namespace supervision
{
struct Muestra
{
    std::uint32_t valor;
    std::uint32_t identificador;
};
void registrar(Muestra& muestra) noexcept;
}
#endif
