// CH03-E10. Una misma codificación se expresa en ambos fragmentos.
#include <string_view>

namespace supervision
{
constexpr std::string_view mensaje{"valor=" "correcto"};
constexpr std::string_view mensaje_utf8{u8"valor=" u8"correcto"};

static_assert(mensaje == mensaje_utf8,
              "Para este texto ASCII los bytes coinciden en C++17");
}
