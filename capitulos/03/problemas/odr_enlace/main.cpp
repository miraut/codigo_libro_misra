#include <cstdint>
std::uint32_t lectura_a() noexcept;
std::uint32_t lectura_b() noexcept;
int main()
{
    return lectura_a() == lectura_b() ? 0 : 1;
}
