#include <cstdint>
namespace caso_odr
{
struct Lectura
{
    std::uint16_t estado;
    std::uint32_t cuenta;
};
std::uint32_t obtener_otro_campo(Lectura const& dato) noexcept
{
    return dato.cuenta;
}
}
// Dos definiciones distintas del mismo tipo en un programa: ODR comprometida.
// Compilar las unidades por separado para estudiar el limite; no enlazarlas.
