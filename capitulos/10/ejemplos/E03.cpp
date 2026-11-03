// CH10-E03. Dos modos de comunicar el error, con contratos distintos.
#include <cstdint>

namespace ejemplo_lanzamiento
{
struct ErrorCalibracion
{
    std::uint32_t canal;
    std::uint32_t codigo;
};

void comprobar_calibracion_incorrecto(std::uint32_t canal)
{
    ErrorCalibracion error{canal, 3U};
    throw &error; // Problemático: se lanza un puntero a una variable local.
}

void comprobar_calibracion(std::uint32_t canal)
{
    throw ErrorCalibracion{canal, 3U}; // Se lanza un objeto por valor.
}
}
