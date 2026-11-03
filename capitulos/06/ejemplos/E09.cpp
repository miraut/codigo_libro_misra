// CH06-E09. La conversion desde una magnitud requiere una decision explicita.
#include <cstdint>

namespace conversiones_clase {
class PeriodoMilisegundos {
public:
    explicit PeriodoMilisegundos(std::uint16_t valor) noexcept : valor_{valor} {}
    std::uint16_t valor() const noexcept { return valor_; }
private:
    std::uint16_t valor_;
};

bool admite_periodo(PeriodoMilisegundos periodo) noexcept {
    return (periodo.valor() >= 10U) && (periodo.valor() <= 500U);
}

bool ejemplo() noexcept {
    // admite_periodo(20U); // No compila: se pide conversion deliberada.
    return admite_periodo(PeriodoMilisegundos{20U});
}
} // namespace conversiones_clase
