// CH14-E15. Comparación problemática: identidad de bytes en lugar de valores.
#include <cstdint>
#include <cstring>

namespace medidas
{
struct Lectura
{
    std::uint32_t secuencia{0U};
    float valor{0.0F};
};

bool mismas_lecturas_por_memoria(Lectura const& primera,
                                Lectura const& segunda)
{
    return std::memcmp(&primera, &segunda, sizeof(Lectura)) == 0;
}
}
