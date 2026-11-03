// CH14-E03. Deduplicación completa mediante unique y erase.
#include <algorithm>
#include <cstdint>
#include <vector>

namespace tramas
{
void eliminar_repeticiones(std::vector<std::uint16_t>& identificadores)
{
    std::sort(identificadores.begin(), identificadores.end());
    auto const nuevo_final =
        std::unique(identificadores.begin(), identificadores.end());
    (void)identificadores.erase(nuevo_final, identificadores.end());
}
}
