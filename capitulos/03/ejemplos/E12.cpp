// CH03-E12. La declaración de función se confunde con un objeto.
#include <cstdint>

namespace supervision
{
struct Temporizador
{
    std::uint32_t periodo{100U};
};

void preparar() noexcept
{
    Temporizador temporizador(); // No crea ningún objeto; declaración local de función.
    Temporizador temporizador_activo{}; // Crea un objeto.
    (void)temporizador_activo.periodo;
}
}
