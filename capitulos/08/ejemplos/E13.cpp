// CH08-E13. Problemático según Rule 28.6.3.
#include <cstdint>
#include <utility>
#include <vector>

struct LoteComandos
{
    std::uint32_t secuencia;
    std::vector<std::uint8_t> contenido;
};

void registrar_lote(std::vector<LoteComandos>& pendientes,
                   LoteComandos lote)
{
    pendientes.push_back(std::move(lote));

    if (!lote.contenido.empty()) // Uso posterior al movimiento potencial.
    {
        // El contenido ya no pertenece necesariamente a 'lote'.
    }
}
