// CH06-E05. Firmas de copia y movimiento: propiedad exclusiva y referencias.
#include <cstdint>
#include <type_traits>
#include <utility>

namespace firmas_especiales {
struct RegistroConcesiones {
    unsigned devoluciones{0U};
    void devolver(std::uint16_t identificador) noexcept {
        if (identificador != 0U) { ++devoluciones; }
    }
};

class Concesion {
public:
    Concesion(RegistroConcesiones& registro, std::uint16_t identificador) noexcept
        : registro_{&registro}, identificador_{identificador} {}

    Concesion(Concesion const&) = delete;
    Concesion& operator=(Concesion const&) = delete;

    Concesion(Concesion&& otra) noexcept
        : registro_{std::exchange(otra.registro_, nullptr)},
          identificador_{std::exchange(otra.identificador_, 0U)} {}

    Concesion& operator=(Concesion&& otra) & noexcept {
        if (this != &otra) {
            devolver();
            registro_ = std::exchange(otra.registro_, nullptr);
            identificador_ = std::exchange(otra.identificador_, 0U);
        }
        return *this;
    }

    ~Concesion() noexcept { devolver(); }
    std::uint16_t identificador() const noexcept { return identificador_; }

private:
    void devolver() noexcept {
        if (registro_ != nullptr) {
            registro_->devolver(identificador_);
            registro_ = nullptr;
            identificador_ = 0U;
        }
    }
    RegistroConcesiones* registro_{nullptr};
    std::uint16_t identificador_{0U};
};

static_assert(std::is_move_constructible<Concesion>::value, "Se transfiere");
static_assert(!std::is_copy_constructible<Concesion>::value, "No se duplica");
} // namespace firmas_especiales
