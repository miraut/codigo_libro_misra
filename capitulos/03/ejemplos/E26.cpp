// CH03-E26. Taller: tres archivos para diagnosticar antes de modificar.
// registro.hpp
#ifndef SUPERVISION_REGISTRO_HPP
#define SUPERVISION_REGISTRO_HPP

#include <cstdint>

namespace supervision
{
using IdRegistro = std::uint16_t;

std::uint32_t registros_procesados{0U};
std::uint32_t contar(IdRegistro id) noexcept
{
    return static_cast<std::uint32_t>(id) + registros_procesados;
}
}
#endif

// cliente_a.cpp
// #include "registro.hpp"
// std::uint32_t cliente_a() noexcept
// {
//     return supervision::contar(1U);
// }

// cliente_b.cpp
// #include "registro.hpp"
// std::uint32_t cliente_b() noexcept
// {
//     return supervision::contar(2U);
// }
