// CH06-E07. La base y todos los miembros quedan inicializados antes del cuerpo.
#include <cstdint>

namespace construccion {
class IdentidadCanal {
public:
    explicit IdentidadCanal(std::uint16_t codigo) noexcept : codigo_{codigo} {}
    std::uint16_t codigo() const noexcept { return codigo_; }
protected:
    ~IdentidadCanal() = default; // Evita la destruccion desde una interfaz base.
private:
    std::uint16_t codigo_{0U};
};

class CanalTermico final : public IdentidadCanal {
public:
    CanalTermico(std::uint16_t codigo, std::uint16_t periodo_ms) noexcept
        : IdentidadCanal{codigo}, periodo_ms_{periodo_ms}, errores_{0U} {}

    std::uint16_t periodo_ms() const noexcept { return periodo_ms_; }
    std::uint16_t errores() const noexcept { return errores_; }

private:
    std::uint16_t periodo_ms_;
    std::uint16_t errores_;
};
} // namespace construccion
