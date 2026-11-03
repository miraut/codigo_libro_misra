// CH04-E13. Resultado modular constante: válido en C++17, cuestionable en diseño.
#include <cstdint>
#include <limits>

namespace constantes
{
constexpr std::uint32_t maximo =
    std::numeric_limits<std::uint32_t>::max();
constexpr std::uint32_t vuelta = maximo + std::uint32_t{1U};
static_assert(vuelta == 0U, "La suma se reduce módulo 2^32");

constexpr std::uint64_t suma_sin_vuelta =
    static_cast<std::uint64_t>(maximo) + std::uint64_t{1U};
static_assert(suma_sin_vuelta == 4'294'967'296ULL,
              "El dominio amplio permite expresar la cantidad matemática");
}
