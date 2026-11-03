// CH03-E11. Identificadores con significado frente a un nombre reservado por la pauta.
#include <cstdint>

namespace supervision
{
std::uint16_t canal_seleccionado(std::uint16_t canal) noexcept
{
    std::uint16_t _canal{canal}; // Deliberadamente no conforme con Rule 5.10.1.
    return _canal;
}
}
