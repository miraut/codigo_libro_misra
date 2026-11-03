// CH03-E05. Rutas y separadores con semántica explícita.
#include <string_view>

namespace supervision
{
constexpr std::string_view ruta_ordinaria{"C:\\datos\\medidas"};
constexpr std::string_view ruta_sin_formato{R"(C:\datos\medidas)"};

static_assert(ruta_ordinaria == ruta_sin_formato,
              "Las dos representaciones deben designar la misma ruta");
}
