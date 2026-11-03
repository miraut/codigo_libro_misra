// CH05-E05. Un parametro de lectura comunica su contrato.
#include <array>
#include <cstdint>

namespace vista_trama {
using Trama = std::array<std::uint8_t, 6U>;

std::uint32_t huella(Trama const& datos) noexcept
{
    std::uint32_t acumulador{2166136261U};
    for (std::uint8_t const octeto : datos)
    {
        acumulador ^= static_cast<std::uint32_t>(octeto);
        acumulador *= 16777619U;
    }
    return acumulador;
}

void marcar_revisada(Trama& datos) noexcept
{
    datos[0U] = 0x5AU; // Modificacion intencional y visible en la firma.
}
} // namespace vista_trama
