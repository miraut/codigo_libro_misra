// CH12-E04. Interfaz de lectura de registros recibidos desde la capa hardware.
#include <cstdint>

namespace ejemplo_periferico
{
struct RegistrosAdquisicion
{
    volatile std::uint32_t estado{0U};
    volatile std::uint32_t dato{0U};
};

struct LecturaDispositivo
{
    bool disponible{false};
    std::uint32_t valor{0U};
};

LecturaDispositivo leer_dispositivo(
    RegistrosAdquisicion volatile& registros) noexcept
{
    std::uint32_t const estado_leido{registros.estado};
    if ((estado_leido & 1U) == 0U)
    {
        return LecturaDispositivo{};
    }

    std::uint32_t const valor_leido{registros.dato};
    return LecturaDispositivo{true, valor_leido};
}
}
