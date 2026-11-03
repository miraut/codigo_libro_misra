// CH03-E09. Sufijos explícitos para cantidades de anchura amplia.
#include <cstdint>
#include <type_traits>

namespace supervision
{
constexpr auto periodo_amplio{5000000000LL};
constexpr auto mascara_amplia{0x100000000ULL};

static_assert(std::is_same<decltype(periodo_amplio), const long long>::value,
              "La grafía LL selecciona long long");
static_assert(mascara_amplia > 0xFFFFFFFFULL,
              "La máscara necesita más de treinta y dos bits");
}
