// CH06-E16. Valor por defecto estatico y despacho virtual dinamico.
#include <cstdint>

namespace contratos_virtuales {
struct InterfazMedida {
    InterfazMedida(InterfazMedida const&) = delete;
    InterfazMedida& operator=(InterfazMedida const&) = delete;
    InterfazMedida(InterfazMedida&&) = delete;
    InterfazMedida& operator=(InterfazMedida&&) = delete;
    virtual ~InterfazMedida() = default;
protected:
    InterfazMedida() = default;
public:
    virtual std::uint16_t calcular(std::uint16_t margen = 1U) const noexcept {
        return margen;
    }
};

struct MedidaTermica final : InterfazMedida {
    std::uint16_t calcular(std::uint16_t margen = 3U) const noexcept override {
        return static_cast<std::uint16_t>(margen * 10U);
    }
};
} // namespace contratos_virtuales
