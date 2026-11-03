#include <cstdint>
std::uint32_t leer_registro_hardware(std::uintptr_t direccion) noexcept
{
    auto const registro =
        reinterpret_cast<volatile std::uint32_t const *>(direccion);
    return *registro;
}
// Deliberadamente no conforme con Rule 8.2.5 y Rule 8.2.6.
// No invocar en PC; se compila a objeto pero nunca se enlaza ni ejecuta.
