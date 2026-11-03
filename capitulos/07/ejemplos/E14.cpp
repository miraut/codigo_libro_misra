// CH07-E14. Dos modelos de almacenamiento.
#include <cstdint>
#include <memory>

namespace procesamiento
{
struct Parametros
{
    std::uint32_t limite;
    std::uint32_t periodo;
};

Parametros parametros_por_valor() noexcept
{
    return Parametros{500U, 20U};
}

std::unique_ptr<Parametros> parametros_dinamicos()
{
    return std::make_unique<Parametros>(Parametros{500U, 20U});
}
}
