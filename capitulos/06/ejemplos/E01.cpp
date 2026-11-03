// CH06-E01. Situacion de riesgo: la autoasignacion por movimiento pierde la conexion.
#include <cstdint>
#include <utility>

namespace apertura_riesgo {
struct RegistroCierres {
    std::uint32_t cantidad{0U};
    void cerrar(std::uint16_t canal) noexcept {
        if (canal != 0U) { ++cantidad; }
    }
};

class ConexionBus {
public:
    ConexionBus(RegistroCierres& registro, std::uint16_t canal) noexcept
        : registro_{registro}, canal_{canal} {}

    ConexionBus(ConexionBus const&) = delete;
    ConexionBus& operator=(ConexionBus const&) = delete;

    ConexionBus(ConexionBus&& otra) noexcept
        : registro_{otra.registro_},
          canal_{std::exchange(otra.canal_, 0U)} {}

    ConexionBus& operator=(ConexionBus&& otra) & noexcept {
        registro_.cerrar(canal_);
        canal_ = otra.canal_;
        otra.canal_ = 0U; // Si hay alias, anula tambien el destino.
        return *this;
    }

    ~ConexionBus() noexcept { registro_.cerrar(canal_); }
    std::uint16_t canal() const noexcept { return canal_; }

private:
    RegistroCierres& registro_;
    std::uint16_t canal_{0U};
};
} // namespace apertura_riesgo
