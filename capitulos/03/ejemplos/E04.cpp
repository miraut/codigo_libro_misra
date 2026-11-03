// CH03-E04. C++17 mantiene los caracteres, pero el texto plantea un riesgo visual.
#include <string_view>

namespace supervision
{
constexpr std::string_view formato_antiguo{"??-??-??"};
constexpr std::string_view formato_claro{"DD-MM-AA"};
}
