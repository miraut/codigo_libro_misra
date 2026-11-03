// CH06-E20. Caso integrador: propiedad exclusiva, parametros y despacho.
#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>

namespace caso_adquisicion {
class ReservaCanal;

class BancoCanales {
public:
    bool esta_reservado(std::size_t canal) const noexcept {
        return (canal < ocupados_.size()) && ocupados_[canal];
    }

private:
    friend class ReservaCanal;
    bool reservar(std::size_t canal) noexcept {
        if ((canal == 0U) || (canal >= ocupados_.size()) || ocupados_[canal]) {
            return false;
        }
        ocupados_[canal] = true;
        return true;
    }

    void liberar(std::size_t canal) noexcept {
        if ((canal > 0U) && (canal < ocupados_.size())) {
            ocupados_[canal] = false;
        }
    }

    std::array<bool, 4U> ocupados_{};
};

class ReservaCanal {
public:
    // Intenta reservar; queda inactiva si el canal no esta disponible.
    ReservaCanal(BancoCanales& banco, std::size_t canal) noexcept
        : banco_{banco.reservar(canal) ? &banco : nullptr},
          canal_{banco_ != nullptr ? canal : 0U} {}

    ReservaCanal(ReservaCanal const&) = delete;
    ReservaCanal& operator=(ReservaCanal const&) = delete;

    ReservaCanal(ReservaCanal&& origen) noexcept
        : banco_{std::exchange(origen.banco_, nullptr)},
          canal_{std::exchange(origen.canal_, 0U)} {}

    ReservaCanal& operator=(ReservaCanal&& origen) & noexcept {
        if (this != &origen) {
            liberar();
            banco_ = std::exchange(origen.banco_, nullptr);
            canal_ = std::exchange(origen.canal_, 0U);
        }
        return *this;
    }

    ~ReservaCanal() noexcept { liberar(); }
    bool activa() const noexcept { return banco_ != nullptr; }

private:
    void liberar() noexcept {
        if (banco_ != nullptr) {
            banco_->liberar(canal_);
            banco_ = nullptr;
            canal_ = 0U;
        }
    }

    BancoCanales* banco_{nullptr};
    std::size_t canal_{0U};
};

struct PerfilAdquisicion {
    std::uint16_t periodo_ms{0U};
    std::uint16_t limite_superior{0U};
};

bool perfil_valido(PerfilAdquisicion const& perfil) noexcept {
    return (perfil.periodo_ms >= 5U) && (perfil.periodo_ms <= 1000U) &&
           (perfil.limite_superior > 0U);
}

class OrigenMedida {
protected:
    OrigenMedida() = default;
public:
    virtual ~OrigenMedida() = default;
    OrigenMedida(OrigenMedida const&) = delete;
    OrigenMedida& operator=(OrigenMedida const&) = delete;
    OrigenMedida(OrigenMedida&&) = delete;
    OrigenMedida& operator=(OrigenMedida&&) = delete;

    virtual bool obtener(std::uint16_t& medida) noexcept = 0;
};

class OrigenFijo final : public OrigenMedida {
public:
    explicit OrigenFijo(std::uint16_t valor) noexcept
        : OrigenMedida{}, valor_{valor} {}

    bool obtener(std::uint16_t& medida) noexcept override {
        medida = valor_;
        return true;
    }

private:
    std::uint16_t valor_{0U};
};

class UnidadAdquisicion {
public:
    // Precondiciones: perfil valido, reserva activa y origen vivo.
    UnidadAdquisicion(OrigenMedida& origen,
                      ReservaCanal&& reserva,
                      PerfilAdquisicion perfil) noexcept
        : origen_{origen}, reserva_{std::move(reserva)}, perfil_{perfil} {}

    bool adquirir(std::uint16_t& medida) noexcept {
        if (!reserva_.activa()) { return false; }
        std::uint16_t lectura{0U};
        if (!origen_.obtener(lectura)) { return false; }
        if (lectura > perfil_.limite_superior) { return false; }
        medida = lectura;
        return true;
    }

private:
    OrigenMedida& origen_;
    ReservaCanal reserva_;
    PerfilAdquisicion perfil_;
};
} // namespace caso_adquisicion
