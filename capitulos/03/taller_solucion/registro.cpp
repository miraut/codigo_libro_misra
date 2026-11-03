#include "registro.hpp"

#include <limits>

namespace supervision
{
ResultadoRegistro Registro::contar(IdRegistro id) noexcept
{
    constexpr auto maximo{std::numeric_limits<std::uint32_t>::max()};
    auto const id_ampliado{static_cast<std::uint32_t>(id)};
    if (registros_procesados_ == maximo ||
        id_ampliado > (maximo - registros_procesados_))
    {
        return ResultadoRegistro{false, 0U};
    }

    auto const resultado{id_ampliado + registros_procesados_};
    ++registros_procesados_;
    return ResultadoRegistro{true, resultado};
}
}
