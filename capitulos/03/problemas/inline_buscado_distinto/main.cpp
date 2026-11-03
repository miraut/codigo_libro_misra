#include <cstdint>
std::uint32_t usar_a() noexcept;
std::uint32_t usar_b() noexcept;
int main()
{
    // No ejecutar: el programa viola la ODR.
    return 0;
}
