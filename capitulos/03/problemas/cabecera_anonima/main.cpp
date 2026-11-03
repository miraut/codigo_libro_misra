#include <cstdint>
std::uint32_t incrementar_a() noexcept;
std::uint32_t incrementar_b() noexcept;
int main()
{
    auto const primero{incrementar_a()};
    auto const segundo{incrementar_b()};
    return primero == 1U && segundo == 1U ? 0 : 1;
}
