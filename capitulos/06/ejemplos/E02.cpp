// CH06-E02. Datos publicos y clase con invariante protegido.
#include <cstdint>

namespace invariantes {
struct MuestraAdquirida {
    std::uint16_t identificador{0U};
    std::uint16_t valor_bruto{0U};
};

class VentanaPresion {
public:
    // Precondicion: minimo <= maximo.
    VentanaPresion(std::uint16_t minimo, std::uint16_t maximo) noexcept
        : minimo_{minimo}, maximo_{maximo} {}

    static bool limites_validos(std::uint16_t minimo,
                                std::uint16_t maximo) noexcept {
        return minimo <= maximo;
    }

    bool contiene(std::uint16_t presion) const noexcept {
        return (minimo_ <= presion) && (presion <= maximo_);
    }

private:
    std::uint16_t minimo_;
    std::uint16_t maximo_;
};
} // namespace invariantes
