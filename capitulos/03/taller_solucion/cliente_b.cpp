#include "registro.hpp"
namespace supervision
{
ResultadoRegistro cliente_b(Registro& registro) noexcept
{
    return registro.contar(2U);
}
}
