// CH05-E12. Una lectura volatile condicionada por un operador logico.
#include <cstdint>

namespace registro_hardware {
extern volatile std::uint32_t registro_estado;

bool hay_incidencia(bool alarma_interna) noexcept
{
    // La lectura del registro no se hace si alarma_interna es true.
    return alarma_interna || ((registro_estado & 0x01U) != 0U);
}

bool hay_incidencia_con_lectura_explicita(bool alarma_interna) noexcept
{
    std::uint32_t const estado_leido = registro_estado;
    bool const alarma_periferico = (estado_leido & 0x01U) != 0U;
    return alarma_interna || alarma_periferico;
}
} // namespace registro_hardware
