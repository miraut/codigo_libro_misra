// CH12-E03. Los accesos a registros quedan ordenados por sentencias.
#include <cstdint>

namespace ejemplo_dos_registros
{
std::uint32_t sumar_sin_orden(volatile std::uint32_t& registro_a,
                             volatile std::uint32_t& registro_b) noexcept
{
    return registro_a + registro_b; // Problemático para Rule 4.6.1.
}

std::uint32_t sumar_con_orden(volatile std::uint32_t& registro_a,
                             volatile std::uint32_t& registro_b) noexcept
{
    std::uint32_t const primera_lectura{registro_a};
    std::uint32_t const segunda_lectura{registro_b};
    return primera_lectura + segunda_lectura;
}
}
