// CH07-E05. Problemático. No desreferenciar 'pendiente'.
#include <cstdint>

namespace diagnostico
{
void registrar() noexcept
{
    std::uint32_t const* pendiente{nullptr};

    {
        std::uint32_t identificador{205U};
        pendiente = &identificador; // El objeto termina al salir del bloque.
    }

    // 'pendiente' ha sobrevivido a 'identificador'. No desreferenciar.
    (void)pendiente;
}
}
