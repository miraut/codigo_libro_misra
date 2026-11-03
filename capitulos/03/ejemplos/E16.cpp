// CH03-E16. Dos cabeceras incompatibles; NO construir un ejecutable para usarlo.
// medidas_adquisicion.hpp
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
}
#endif

// medidas_diagnostico.hpp
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
}
#endif
