#include "registro.hpp"
namespace supervision
{
ResultadoRegistro cliente_a(Registro& registro) noexcept
{
    return registro.contar(1U);
}
}
