// CH04-E16. Una enumeración simbólica sin tipo subyacente fijo.
#include <cstdint>

namespace enumeracion_simbolica
{
enum Aviso
{
    ninguno,
    vigilancia,
    parada
};

bool es_critico(Aviso valor) noexcept
{
    return valor == parada;  // Comparación entre valores del mismo enum.
}

Aviso elegir(bool grave) noexcept
{
    return grave ? parada : vigilancia;
}
}
