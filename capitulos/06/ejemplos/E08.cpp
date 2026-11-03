// CH06-E08. Dos problemas de inicializacion que deben revisarse por separado.
#include <cstdint>

namespace construccion_fragil {
class ConfiguracionTardia {
public:
    explicit ConfiguracionTardia(std::uint16_t periodo) noexcept {
        periodo_ms_ = periodo; // Asignacion en el cuerpo; no inicializacion del miembro.
    }
    std::uint16_t periodo_ms() const noexcept { return periodo_ms_; }
private:
    std::uint16_t periodo_ms_;
};

class OrdenEquivocado {
public:
    explicit OrdenEquivocado(std::uint16_t limite) noexcept
        : limite_{limite}, margen_{static_cast<std::uint16_t>(limite_ + 1U)} {}
    std::uint16_t margen() const noexcept { return margen_; }
private:
    std::uint16_t margen_;  // Se inicializa ANTES que limite_.
    std::uint16_t limite_;
};
} // namespace construccion_fragil
