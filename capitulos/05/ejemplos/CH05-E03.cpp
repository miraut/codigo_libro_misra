// CH05-E03. Construir un resultado de dominio, en lugar de inventar un centinela.
#include <cstdint>
#include <optional>

namespace resultado_valido {
std::optional<std::uint16_t> medir(bool conversion_completa,
                                  std::uint16_t dato_crudo) noexcept
{
    if (!conversion_completa)
    {
        return std::nullopt;
    }

    if (dato_crudo > 2000U)
    {
        return std::nullopt;
    }

    return dato_crudo;
}

std::uint16_t obtener_o_conservar(bool conversion_completa,
                                  std::uint16_t dato_crudo,
                                  std::uint16_t ultimo_valido) noexcept
{
    std::optional<std::uint16_t> const nueva =
        medir(conversion_completa, dato_crudo);

    if (nueva.has_value())
    {
        return *nueva;
    }

    return ultimo_valido;
}
} // namespace resultado_valido
