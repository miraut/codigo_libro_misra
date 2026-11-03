// CH15-E04. Valor recibido y utilizado por el llamador.
#include <cstdint>

std::uint32_t obtener_numero_de_ciclos() noexcept
{
    return 12U;
}

bool comprobar_ciclos() noexcept
{
    std::uint32_t const ciclos_observados = obtener_numero_de_ciclos();
    return ciclos_observados <= 20U;
}
