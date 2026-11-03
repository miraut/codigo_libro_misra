// CH15-E03. Ejemplo intencional de retorno ignorado, para pruebas de deteccion.
#include <cstdint>

std::uint32_t obtener_numero_de_ciclos() noexcept
{
    return 12U;
}

void descartar_resultado_sin_indicarlo() noexcept
{
    obtener_numero_de_ciclos();
}
