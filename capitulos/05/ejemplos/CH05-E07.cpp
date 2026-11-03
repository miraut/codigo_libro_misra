// CH05-E07. C++17 puede permitir una escritura que la Rule 8.2.3 restringe.
#include <cstdint>

namespace retirada_const {
void cambio_no_justificado(std::uint16_t const& vista) noexcept
{
    std::uint16_t& mutable_por_cast =
        const_cast<std::uint16_t&>(vista); // Infraccion de Rule 8.2.3.
    mutable_por_cast = 27U; // Solo definido si el objeto original no es const.
}

std::uint16_t consultar(std::uint16_t const& vista) noexcept
{
    return vista; // No es necesaria ninguna retirada de cualificadores.
}
} // namespace retirada_const
