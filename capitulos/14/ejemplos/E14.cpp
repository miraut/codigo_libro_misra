// CH14-E14. Dependencia de un desplazamiento físico mediante offsetof.
#include <cstddef>
#include <cstdint>

namespace protocolo
{
struct CabeceraLocal
{
    std::uint16_t longitud{0U};
    std::uint8_t tipo{0U};
};

std::size_t desplazamiento_tipo() noexcept
{
    return offsetof(CabeceraLocal, tipo);
}
}
