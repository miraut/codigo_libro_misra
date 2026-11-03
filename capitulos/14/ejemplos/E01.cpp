// CH14-E01. Implementación problemática: copia de bytes sobre un objeto C++.
#include <array>
#include <cstdint>
#include <cstring>
#include <string>

namespace configuracion
{
struct EstadoEquipo
{
    std::uint16_t periodo_ms{20U};
    std::string descripcion{"sin configurar"};
};

void restaurar_estado(
    EstadoEquipo& estado,
    std::array<unsigned char, sizeof(EstadoEquipo)> const& trama)
{
    std::memcpy(&estado, trama.data(), trama.size());
}
}
