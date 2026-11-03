// CH03-E06. El final de un token determina qué caracteres pertenecen al escape.
#include <array>
#include <cstdint>

namespace supervision
{
constexpr char secuencia_ambigua[]{"\x1A"};
constexpr char secuencia_separada[]{"\x01" "A"};
constexpr char escape_sin_terminar[]{"\x41G"}; // No conforme con Rule 5.13.2.
constexpr char escape_terminado[]{"\x41" "G"};

static_assert(sizeof(secuencia_ambigua) == 2U,
              "El primer literal contiene un carácter más el terminador");
static_assert(sizeof(secuencia_separada) == 3U,
              "El segundo literal contiene dos caracteres más el terminador");
static_assert(sizeof(escape_sin_terminar) == sizeof(escape_terminado),
              "La coincidencia del valor no elimina la diferencia de escritura");
}
