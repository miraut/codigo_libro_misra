// CH06-E06. Gestion de la autoasignacion por movimiento.
#include <cstdint>
#include <utility>

namespace apertura_corregida {
struct RegistroCierres {
    std::uint32_t cantidad{0U};
    void cerrar(std::uint16_t canal) noexcept {
        if (canal != 0U) { ++cantidad; }
    }
};

class ConexionBus {
public:
    ConexionBus(RegistroCierres& registro, std::uint16_t canal) noexcept
        : registro_{&registro}, canal_{canal} {}

    ConexionBus(ConexionBus const&) = delete;
    ConexionBus& operator=(ConexionBus const&) = delete;

    ConexionBus(ConexionBus&& otra) noexcept
        : registro_{std::exchange(otra.registro_, nullptr)},
          canal_{std::exchange(otra.canal_, 0U)} {}

    ConexionBus& operator=(ConexionBus&& otra) & noexcept {
        if (this != std::addressof(otra)) {
            liberar();
            registro_ = std::exchange(otra.registro_, nullptr);
            canal_ = std::exchange(otra.canal_, 0U);
        }
        return *this;
    }

    ~ConexionBus() noexcept { liberar(); }
    std::uint16_t canal() const noexcept { return canal_; }

private:
    void liberar() noexcept {
        if (registro_ != nullptr) {
            registro_->cerrar(canal_);
            registro_ = nullptr;
            canal_ = 0U;
        }
    }

    RegistroCierres* registro_{nullptr};
    std::uint16_t canal_{0U};
};
} // namespace apertura_corregida
