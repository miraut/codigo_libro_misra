// CH14-E16. Decodificación de campos de un protocolo binario definido.
#include <array>
#include <cstdint>

namespace protocolo
{
struct Lectura
{
    std::uint16_t secuencia{0U};
    std::uint16_t valor{0U};
};

Lectura decodificar(std::array<std::uint8_t, 4U> const& trama) noexcept
{
    auto const leer_dos_octetos = [](std::uint8_t alto,
                                     std::uint8_t bajo) noexcept
    {
        auto const combinado =
            (static_cast<std::uint32_t>(alto) << 8U) |
            static_cast<std::uint32_t>(bajo);
        return static_cast<std::uint16_t>(combinado);
    };

    return {leer_dos_octetos(trama[0], trama[1]),
            leer_dos_octetos(trama[2], trama[3])};
}
}
