// CH03-E14. Interfaz con ámbito nombrado y punto de entrada inequívoco.
#include <cstdint>

namespace supervision
{
std::uint32_t version_protocolo() noexcept
{
    return 3U;
}
}

int main()
{
    return supervision::version_protocolo() == 3U ? 0 : 1;
}
