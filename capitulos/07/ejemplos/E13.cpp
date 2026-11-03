// CH07-E13. Contrastar intención de llamada y dirección.
namespace control
{
bool permiso_de_arranque() noexcept;

bool comprobar() noexcept
{
    return permiso_de_arranque(); // Se invoca la función.
}

void registrar_callback() noexcept
{
    bool (*callback)() noexcept = &permiso_de_arranque;
    (void)callback; // Se conserva una dirección de función.
}

// Problemático: if (permiso_de_arranque) { ... }
// La condición no invoca la función.
}
