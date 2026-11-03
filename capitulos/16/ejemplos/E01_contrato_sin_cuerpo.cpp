#include <cstdint>
extern "C" std::uint32_t cots_leer_muestra() noexcept;

bool medida_en_rango() noexcept
{
    return cots_leer_muestra() <= 4095U;
}
// Solo compilacion -c: no hay definicion real de proveedor en este ejemplo.
