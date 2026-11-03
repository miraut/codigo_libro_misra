// CH12-E12. Riesgo adicional: el puntero se usa tras otra llamada a getenv.
#include <cstdlib>

namespace ejemplo_puntero_prestado
{
char const* consultar_dos_opciones() noexcept
{
    char const* primera_opcion{std::getenv("MODO_ADQUISICION")};
    char const* segunda_opcion{std::getenv("NIVEL_DIAGNOSTICO")};
    (void)segunda_opcion;
    return primera_opcion; // Problemático para Rule 25.5.3.
}
}
