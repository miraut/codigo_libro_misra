#include "escala.hpp"
#include <cstdint>
std::uint32_t lectura_b() noexcept
{
    return supervision::escala_microvoltios;
}
