// CH02-E08. Uso sintáctico sin observación del valor escrito.
#include <cstdint>

void actualizar_temporal(std::uint16_t lectura) noexcept
{
    std::uint16_t temporal;
    temporal = lectura;
}
