#include <cstdint>
namespace caso_odr
{
struct Lectura
{
    std::uint32_t cuenta;
    std::uint16_t estado;
};
std::uint32_t obtener_cuenta(Lectura const& dato) noexcept
{
    return dato.cuenta;
}
}
