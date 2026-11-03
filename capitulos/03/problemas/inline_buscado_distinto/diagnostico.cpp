#include <cstdint>
namespace supervision
{
std::uint32_t obtener_escala(double valor) noexcept;
}
#include "transformacion.hpp"
std::uint32_t usar_b() noexcept
{
    return supervision::aplicar(2U);
}
