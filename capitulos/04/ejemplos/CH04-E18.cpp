// CH04-E18. Decodificación de tres octetos, independiente del orden de bytes de la CPU.
#include <array>
#include <climits>
#include <cstdint>
#include <optional>

namespace trama
{
static_assert(CHAR_BIT == 8, "El protocolo presupone octetos de ocho bits");

enum class Estado : std::uint8_t { espera = 0U, medida = 1U, alarma = 2U };

struct Muestra
{
    std::uint16_t magnitud;
    Estado estado;
    bool alarma_activa;
};

std::optional<Muestra> decodificar(
    std::array<std::uint8_t, 3> const& mensaje) noexcept
{
    std::uint32_t const control =
        static_cast<std::uint32_t>(mensaje[0]);
    std::uint32_t const estado_numerico = (control >> 1U) & 0x3U;
    std::uint32_t const magnitud =
        (static_cast<std::uint32_t>(mensaje[1]) << 8U) |
         static_cast<std::uint32_t>(mensaje[2]);

    if (((control & 0xF8U) != 0U) ||
        (estado_numerico > 2U) ||
        (magnitud > 1023U))
    {
        return std::nullopt;
    }

    Estado const estado =
        static_cast<Estado>(static_cast<std::uint8_t>(estado_numerico));

    return Muestra{static_cast<std::uint16_t>(magnitud),
                   estado,
                   (control & 0x1U) != 0U};
}
}
