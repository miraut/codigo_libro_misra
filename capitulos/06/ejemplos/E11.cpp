// CH06-E11. Mismo tipo, dos significados para la inicializacion.
#include <array>
#include <cstddef>
#include <cstdint>
#include <initializer_list>

namespace constructores_ambivalentes {
class TablaUmbrales {
public:
    TablaUmbrales(std::size_t cantidad, std::uint16_t valor) noexcept
        : cantidad_{cantidad <= datos_.size() ? cantidad : datos_.size()} {
        for (std::size_t indice{0U}; indice < cantidad_; ++indice) {
            datos_[indice] = valor;
        }
    }

    TablaUmbrales(std::initializer_list<std::uint16_t> valores) noexcept {
        for (std::uint16_t valor : valores) {
            if (cantidad_ < datos_.size()) {
                datos_[cantidad_] = valor;
                ++cantidad_;
            }
        }
    }

    std::size_t cantidad() const noexcept { return cantidad_; }
    std::uint16_t primero() const noexcept { return datos_[0U]; }

private:
    std::array<std::uint16_t, 8U> datos_{};
    std::size_t cantidad_{0U};
};
} // namespace constructores_ambivalentes
