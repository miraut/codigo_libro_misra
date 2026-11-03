// CH07-E12. Dos llamadas con significado diferente.
#include <cstdint>

namespace comunicaciones
{
void seleccionar(std::int32_t) noexcept {}
void seleccionar(std::int32_t const*) noexcept {}

void ejemplo() noexcept
{
    seleccionar(0);       // Selecciona la sobrecarga numérica.
    seleccionar(nullptr); // Selecciona la sobrecarga de puntero.

    std::int32_t const* ausente{nullptr};
    (void)ausente;
    // Evitar: std::int32_t const* ausente{0};
}
}
