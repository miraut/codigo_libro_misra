// CH14-E02. Uso problemático: se ignora el límite lógico devuelto por unique.
#include <algorithm>
#include <cstdint>
#include <vector>

namespace tramas
{
void eliminar_repeticiones(std::vector<std::uint16_t>& identificadores)
{
    std::sort(identificadores.begin(), identificadores.end());
    std::unique(identificadores.begin(), identificadores.end());
}
}
