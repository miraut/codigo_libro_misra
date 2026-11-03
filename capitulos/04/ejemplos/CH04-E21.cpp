// CH04-E21. Ida y vuelta válidas en C++17; vuelta restringida por MISRA.
#include <cstdint>

namespace punteros_genericos
{
std::uint32_t leer_por_interfaz_generica(std::uint32_t& valor) noexcept
{
    void* contexto = &valor;
    auto* recuperado = static_cast<std::uint32_t*>(contexto);
    // Conversión definida aquí, pero contraria a Rule 8.2.6.
    return *recuperado;
}
}
