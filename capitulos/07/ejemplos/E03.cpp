// CH07-E03. Problemático. No invocar la lambda devuelta.
#include <cstdint>

namespace diagnostico
{
auto crear_comprobador(std::uint32_t limite) noexcept
{
    std::uint32_t umbral{limite};
    return [&umbral](std::uint32_t lectura) noexcept {
        return lectura <= umbral;
    };
}
}
