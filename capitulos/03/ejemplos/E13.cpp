// CH03-E13. El resultado utiliza un umbral local distinto del recibido.
#include <cstdint>

namespace supervision
{
bool necesita_revision(std::uint16_t lectura,
                       std::uint16_t limite) noexcept
{
    if (lectura != 0U)
    {
        std::uint16_t limite{100U}; // Oculta el parámetro; no conforme.
        return lectura > limite;
    }
    return false;
}
}
