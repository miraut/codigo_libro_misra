// CH04-E23. El cast compila; llamar al puntero transformado sería indebido.
#include <cstdint>

namespace funciones
{
std::uint32_t medir(std::uint32_t lectura) noexcept { return lectura; }

using Lectura = std::uint32_t (*)(std::uint32_t) noexcept;
using Control = bool (*)(std::uint32_t) noexcept;

Lectura tipo_correcto() noexcept
{
    return &medir;
}

Control tipo_incompatible() noexcept
{
    return reinterpret_cast<Control>(&medir); // Rule 8.2.4 y Rule 8.2.5.
}
}
