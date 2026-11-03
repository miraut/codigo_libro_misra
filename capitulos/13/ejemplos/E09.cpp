// CH13-E09. Comprobación directa de una característica opcional.
#include <cstdint>

#if defined(INCLUIR_DIAGNOSTICO) && (INCLUIR_DIAGNOSTICO == 1)
#define DIAGNOSTICO_ACTIVO 1
#else
#define DIAGNOSTICO_ACTIVO 0
#endif

namespace supervision
{
inline constexpr bool diagnostico_activo{DIAGNOSTICO_ACTIVO == 1};
}
