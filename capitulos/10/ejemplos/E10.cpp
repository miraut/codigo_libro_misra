// CH10-E10. Decisión de reacción separada del mecanismo de parada.
#include <cstdint>

namespace ejemplo_reaccion
{
enum class FalloSistema : std::uint8_t
{
    ninguno,
    trama_invalida,
    estado_incoherente
};

enum class Reaccion : std::uint8_t
{
    continuar,
    descartar_trama,
    solicitar_estado_seguro
};

Reaccion decidir_reaccion(FalloSistema fallo) noexcept
{
    switch (fallo)
    {
    case FalloSistema::ninguno:
        return Reaccion::continuar;
    case FalloSistema::trama_invalida:
        return Reaccion::descartar_trama;
    case FalloSistema::estado_incoherente:
        return Reaccion::solicitar_estado_seguro;
    }
    return Reaccion::solicitar_estado_seguro;
}
}
