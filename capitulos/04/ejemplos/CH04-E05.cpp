// CH04-E05. La excepción contextual no convierte el puntero en un bool asignable.
#include <cstdint>

namespace condiciones
{
bool existe(std::uint32_t const* valor) noexcept
{
    if (valor)  // Conversión contextual desde puntero: excepción de Rule 7.0.2.
    {
        return true;
    }
    return false;
}

bool existe_de_forma_explicita(std::uint32_t const* valor) noexcept
{
    bool const disponible = (valor != nullptr);
    return disponible;
}
}
