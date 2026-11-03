#include "estado.hpp"
#include <cstdint>
std::uint32_t incrementar_a() noexcept
{
    return ++supervision::muestras;
}
