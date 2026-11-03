// CH06-E12. Dos operaciones distintas reciben nombres distintos.
#include <array>
#include <cstddef>
#include <cstdint>
#include <initializer_list>

namespace fabricas_umbrales {
class TablaUmbrales {
public:
    TablaUmbrales() = default;

    static bool repetir(std::size_t cantidad, std::uint16_t valor,
                        TablaUmbrales& destino) noexcept {
        if (cantidad > destino.datos_.size()) { return false; }
        TablaUmbrales temporal{};
        for (std::size_t indice{0U}; indice < cantidad; ++indice) {
            temporal.datos_[indice] = valor;
        }
        temporal.cantidad_ = cantidad;
        destino = temporal;
        return true;
    }

    static bool desde_lista(std::initializer_list<std::uint16_t> valores,
                            TablaUmbrales& destino) noexcept {
        if (valores.size() > destino.datos_.size()) { return false; }
        TablaUmbrales temporal{};
        for (std::uint16_t valor : valores) {
            temporal.datos_[temporal.cantidad_] = valor;
            ++temporal.cantidad_;
        }
        destino = temporal;
        return true;
    }

    std::size_t cantidad() const noexcept { return cantidad_; }
    std::uint16_t primero() const noexcept { return datos_[0U]; }

private:
    std::array<std::uint16_t, 8U> datos_{};
    std::size_t cantidad_{0U};
};
} // namespace fabricas_umbrales
