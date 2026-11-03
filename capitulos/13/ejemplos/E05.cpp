// CH13-E05. Contenido de medicion.hpp.
#ifndef GUIA_MISRA_MEDICION_HPP
#define GUIA_MISRA_MEDICION_HPP

#include <cstdint>

namespace supervision
{
struct Medicion
{
    std::uint32_t secuencia{0U};
    std::uint16_t valor{0U};
};
}

#endif
