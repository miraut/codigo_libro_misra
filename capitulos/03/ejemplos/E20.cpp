// CH03-E20. Función auxiliar con enlace interno en el archivo de implementación.
#include <cstdint>

namespace supervision
{
namespace
{
constexpr std::uint32_t microvoltios_por_unidad{25U};

std::uint32_t escalar(std::uint16_t valor) noexcept
{
    return static_cast<std::uint32_t>(valor) * microvoltios_por_unidad;
}
}

std::uint32_t lectura_convertida(std::uint16_t valor) noexcept
{
    return escalar(valor);
}
}
