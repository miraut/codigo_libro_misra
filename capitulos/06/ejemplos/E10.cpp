// CH06-E10. Conversion explicita desde un resultado de reserva a bool.
namespace conversion_explicita_resultado {
class ResultadoReserva {
public:
    explicit ResultadoReserva(bool aceptada) noexcept : aceptada_{aceptada} {}

    explicit operator bool() const noexcept { return aceptada_; }

private:
    bool aceptada_{false};
};

bool puede_iniciar(ResultadoReserva const& reserva) noexcept {
    if (reserva) { // La conversion contextual a bool admite explicit.
        return true;
    }
    return false;
}
} // namespace conversion_explicita_resultado
