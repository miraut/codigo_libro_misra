// CH03-E08. El contexto de conversión no decide el tipo del literal.
#include <cstdint>
#include <type_traits>

namespace supervision
{
constexpr std::uint32_t margen_con_sufijo{32768U};
constexpr std::uint32_t margen_sin_sufijo{32768};

static_assert(margen_con_sufijo == margen_sin_sufijo,
              "El valor convertido coincide en ambos casos");
static_assert(std::is_signed<decltype(32768)>::value,
              "El literal decimal 32768 tiene tipo con signo");
}
