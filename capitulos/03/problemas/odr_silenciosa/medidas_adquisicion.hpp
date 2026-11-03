#ifndef SUPERVISION_MEDIDAS_ADQUISICION_HPP
#define SUPERVISION_MEDIDAS_ADQUISICION_HPP
#include <cstdint>
namespace supervision
{
struct Muestra
{
    std::uint32_t identificador;
    std::uint32_t valor;
};
void registrar(Muestra& muestra) noexcept;
}
#endif
