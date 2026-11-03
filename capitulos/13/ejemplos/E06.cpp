// CH13-E06. Selección válida de un nombre de cabecera por macro.
#define CABECERA_TIPOS <cstdint>
#include CABECERA_TIPOS

namespace supervision
{
inline constexpr std::uint32_t identificador_equipo{12U};
}
