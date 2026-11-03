// CH04-E24. Dos fronteras: el acceso dependiente del objetivo y su uso lógico.
#include <cstdint>

namespace hardware
{
// Código ilustrativo dependiente de la plataforma: no invocar en pruebas host.
volatile std::uint32_t* registro_por_direccion(
    std::uintptr_t direccion) noexcept
{
    return reinterpret_cast<volatile std::uint32_t*>(direccion);
    // Uso deliberadamente restringido por Rule 8.2.6 y Rule 8.2.5.
}

class LectorRegistro
{
public:
    virtual ~LectorRegistro() = default;
    virtual std::uint32_t leer() const noexcept = 0;
};

class LectorSimulado final : public LectorRegistro
{
public:
    explicit LectorSimulado(std::uint32_t valor) noexcept : valor_{valor} {}
    std::uint32_t leer() const noexcept override { return valor_; }

private:
    std::uint32_t valor_;
};

bool comprobar_mascara(LectorRegistro const& lector) noexcept
{
    std::uint32_t const dato = lector.leer();
    return (dato & 0x8U) != 0U;
}
}
