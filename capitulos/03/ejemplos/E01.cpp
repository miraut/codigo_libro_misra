// CH03-E01. Tres archivos. Diseño problemático: definición externa en una cabecera.
// escala.hpp
#ifndef SUPERVISION_ESCALA_HPP
#define SUPERVISION_ESCALA_HPP

#include <cstdint>

namespace supervision
{
std::uint32_t escala_microvoltios{25U};
}

#endif

// adquisicion.cpp
// #include "escala.hpp"
// std::uint32_t convertir(std::uint16_t lectura) noexcept
// {
//     return static_cast<std::uint32_t>(lectura) *
//            supervision::escala_microvoltios;
// }

// diagnostico.cpp
// #include "escala.hpp"
// std::uint32_t escala_diagnostico() noexcept
// {
//     return supervision::escala_microvoltios;
// }
