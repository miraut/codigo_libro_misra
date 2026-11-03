// CH07-E04. La lambda conserva una copia.
#include <cstdint>

namespace diagnostico
{
auto crear_comprobador(std::uint32_t limite) noexcept
{
    std::uint32_t const umbral{limite};
    return [umbral](std::uint32_t lectura) noexcept {
        return lectura <= umbral;
    };
}
}
