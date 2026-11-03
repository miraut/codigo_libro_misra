// CH04-E10. La promoción numérica interviene en la selección de sobrecarga.
#include <cstdint>

namespace sobrecargas
{
enum class Destino : std::uint8_t { entero_con_signo, entero_sin_signo };

Destino enviar(std::int32_t) noexcept { return Destino::entero_con_signo; }
Destino enviar(std::uint32_t) noexcept { return Destino::entero_sin_signo; }

Destino enviar_contador(std::uint16_t contador) noexcept
{
    return enviar(static_cast<std::uint32_t>(contador));
}
}
