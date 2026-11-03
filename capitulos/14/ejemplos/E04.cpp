// CH14-E04. Uso problemático: el predicado modifica estado externo.
#include <algorithm>
#include <cstdint>
#include <vector>

namespace medidas
{
void retirar_invalidas(std::vector<std::uint16_t>& lecturas,
                       std::uint16_t limite,
                       std::uint32_t& contador_rechazos)
{
    auto const nuevo_final = std::remove_if(
        lecturas.begin(), lecturas.end(),
        [&contador_rechazos, limite](std::uint16_t lectura)
        {
            if (lectura > limite)
            {
                ++contador_rechazos;
                return true;
            }
            return false;
        });
    (void)lecturas.erase(nuevo_final, lecturas.end());
}
}
