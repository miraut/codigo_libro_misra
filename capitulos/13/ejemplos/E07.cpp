// CH13-E07. Macro auxiliar limitada al archivo que la declara.
#include <cstdint>

#define CODIGO_INICIAL 7U

namespace supervision
{
inline constexpr std::uint32_t codigo_arranque{CODIGO_INICIAL};
}

#undef CODIGO_INICIAL
