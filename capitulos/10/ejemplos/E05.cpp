// CH10-E05. Registrar una decisión local y conservar el error original.
#include <cstdint>

namespace ejemplo_relanzamiento
{
struct ErrorLectura
{
    std::uint32_t codigo;
};

void validar_lectura(bool correcta)
{
    if (!correcta)
    {
        throw ErrorLectura{11U};
    }
}

std::uint32_t gestionar_lectura(bool correcta,
                                std::uint32_t& codigo_diagnostico)
{
    try
    {
        validar_lectura(correcta);
        return 5U;
    }
    catch (ErrorLectura const& error)
    {
        codigo_diagnostico = error.codigo;
        throw; // Relanzamiento dentro del propio catch.
    }
}
}
