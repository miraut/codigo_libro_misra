// CH07-E08b. Un alias puede ocultar niveles de indirección.
#include <cstdint>

namespace adaptacion
{
using DireccionByte = std::uint8_t*;

void actualizar_legacy(DireccionByte** destino); // Equivale a uint8_t***.

struct Direcciones
{
    std::uint8_t* entrada;
    std::uint8_t* salida;
};

void actualizar(Direcciones& estado);
}
