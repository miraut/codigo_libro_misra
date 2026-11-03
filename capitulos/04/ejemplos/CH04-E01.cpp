// CH04-E01. C++17 bien formado; resultado definido, aunque sorprendente.
#include <cstdint>

namespace apertura
{
struct Evaluacion
{
    std::uint32_t pulsos_corregidos;
    bool alarma;
};

Evaluacion evaluar(std::uint32_t pulsos,
                   std::int32_t correccion,
                   std::uint32_t umbral) noexcept
{
    auto const calculado = pulsos + correccion;
    return {calculado, calculado > umbral};
}
}
