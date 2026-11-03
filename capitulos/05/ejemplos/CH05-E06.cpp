// CH05-E06. Constancia del destino y constancia del puntero.
#include <cstdint>

namespace niveles_const {
std::uint8_t observar(std::uint8_t const* datos) noexcept
{
    return datos[0U]; // Precondicion: datos apunta al menos a un octeto valido.
}

void sustituir_primero(std::uint8_t* const datos,
                       std::uint8_t nuevo) noexcept
{
    datos[0U] = nuevo;
}

std::uint8_t leer_con_referencia(std::uint8_t const& valor) noexcept
{
    return valor;
}
} // namespace niveles_const
