// CH08-E14. La información de seguimiento se conserva antes de mover.
#include <cstdint>
#include <utility>
#include <vector>

struct LoteComandos
{
    std::uint32_t secuencia;
    std::vector<std::uint8_t> contenido;
};

struct ResultadoRegistro
{
    std::uint32_t secuencia;
    bool tenia_contenido;
};

ResultadoRegistro registrar_lote(
    std::vector<LoteComandos>& pendientes,
    LoteComandos lote)
{
    ResultadoRegistro resultado{
        lote.secuencia,
        !lote.contenido.empty()
    };

    pendientes.push_back(std::move(lote));
    return resultado;
}
