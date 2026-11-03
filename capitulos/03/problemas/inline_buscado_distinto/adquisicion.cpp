#include <cstdint>
namespace supervision
{
std::uint32_t obtener_escala(std::uint32_t valor) noexcept;
}
#include "transformacion.hpp"
std::uint32_t usar_a() noexcept
{
    return supervision::aplicar(2U);
}
