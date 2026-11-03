// CH04-E12. El signo original y el tipo promocionado importan.
#include <cstdint>
#include <type_traits>

namespace unarios
{
static_assert(std::is_same_v<decltype(-std::uint8_t{3U}), int>,
              "En este entorno la negación de un octeto produce int");

std::uint32_t negar_modular(std::uint32_t valor) noexcept
{
    return -valor;  // Resultado sin signo; Rule 8.3.1 (Advisory).
}

std::int64_t cambio_de_signo(std::uint32_t valor) noexcept
{
    return -static_cast<std::int64_t>(valor);
}
}
