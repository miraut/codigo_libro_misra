// CH06-E13. Una funcion derivada puede ocultar una sobrecarga heredada.
#include <cstdint>

namespace sobrecargas_heredadas {
struct RegistroBase {
    std::uint16_t registrar(std::uint16_t codigo) noexcept { return codigo; }
};

struct RegistroConfuso : RegistroBase {
    std::uint16_t registrar(float lectura) noexcept {
        return static_cast<std::uint16_t>(lectura);
    }
};

struct RegistroExplicito : RegistroBase {
    using RegistroBase::registrar;
    std::uint16_t registrar(float lectura) noexcept {
        return static_cast<std::uint16_t>(lectura);
    }
};
} // namespace sobrecargas_heredadas
