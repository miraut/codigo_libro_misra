#include <cstdint>
namespace supervision
{
std::uint32_t obtener_escala(std::uint32_t valor) noexcept
{
    return valor + 1U;
}
std::uint32_t obtener_escala(double valor) noexcept
{
    return static_cast<std::uint32_t>(valor) + 2U;
}
}
