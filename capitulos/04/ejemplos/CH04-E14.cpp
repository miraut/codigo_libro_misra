// CH04-E14. La validación del protocolo precede a la conversión al estado.
#include <cstdint>
#include <optional>

namespace estados
{
enum class Estado : std::uint8_t
{
    espera = 0U,
    midiendo = 1U,
    alarma = 2U
};

std::optional<Estado> interpretar(std::uint8_t codigo) noexcept
{
    switch (codigo)
    {
        case 0U: return Estado::espera;
        case 1U: return Estado::midiendo;
        case 2U: return Estado::alarma;
        default: return std::nullopt;
    }
}

bool admite_muestras(Estado estado) noexcept
{
    return estado == Estado::midiendo;
}
}
