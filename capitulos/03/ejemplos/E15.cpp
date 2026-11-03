// CH03-E15. Cabecera y archivo de implementación: una interfaz, una definición.
// conversion.hpp
#ifndef SUPERVISION_CONVERSION_HPP
#define SUPERVISION_CONVERSION_HPP

#include <cstdint>

namespace supervision
{
using ValorCrudo = std::uint16_t;
std::uint32_t convertir(ValorCrudo valor) noexcept;
}

#endif

// conversion.cpp
// #include "conversion.hpp"
// namespace supervision
// {
// std::uint32_t convertir(ValorCrudo valor) noexcept
// {
//     return static_cast<std::uint32_t>(valor) * 25U;
// }
// }
