// CH02-E05. Dos casos distintos: instrucción inalcanzable y condición invariante.
#include <cstdint>

namespace supervision
{
std::uint32_t seleccionar_valor(std::uint32_t cantidad) noexcept
{
    if (cantidad == 0U)
    {
        return 0U;
    }

    if (cantidad > 0U) // Verdadero siempre que se alcance esta línea.
    {
        return cantidad;
    }
    else
    {
        return 0U; // Rama semánticamente imposible bajo el contexto anterior.
    }
}
}
