#include "escala.hpp"
#include <cstdint>
std::uint32_t lectura_a() noexcept
{
    return supervision::escala_microvoltios;
}
