// CH14-E05. Criterio sin efectos persistentes y recuento separado.
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace medidas
{
std::size_t retirar_invalidas(std::vector<std::uint16_t>& lecturas,
                              std::uint16_t limite)
{
    auto const excede_limite = [limite](std::uint16_t lectura) noexcept
    {
        return lectura > limite;
    };

    auto const rechazadas = static_cast<std::size_t>(
        std::count_if(lecturas.begin(), lecturas.end(), excede_limite));
    auto const nuevo_final =
        std::remove_if(lecturas.begin(), lecturas.end(), excede_limite);
    (void)lecturas.erase(nuevo_final, lecturas.end());
    return rechazadas;
}
}
