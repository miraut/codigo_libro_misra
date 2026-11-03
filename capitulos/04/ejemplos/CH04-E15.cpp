// CH04-E15. Dos maneras de introducir un alias numérico.
#include <cstdint>

namespace valores_enumerados
{
enum class EstadosConColision : std::uint8_t
{
    espera = 1U,
    activo,             // Se obtiene implícitamente el valor 2.
    revision = 2U       // Deliberadamente no conforme con Rule 11.6.3.
};

enum class EstadosConAlias : std::uint8_t
{
    espera = 1U,
    activo,
    revision = activo   // Alias explícito contemplado por la excepción.
};

static_assert(static_cast<std::uint8_t>(EstadosConAlias::activo) == 2U,
              "El alias conserva el valor del enumerador nombrado");
}
