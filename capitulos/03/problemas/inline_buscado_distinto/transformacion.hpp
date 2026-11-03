#ifndef SUPERVISION_TRANSFORMACION_HPP
#define SUPERVISION_TRANSFORMACION_HPP
#include <cstdint>
namespace supervision
{
inline std::uint32_t aplicar(std::uint32_t lectura) noexcept
{
    return obtener_escala(lectura);
}
}
#endif
