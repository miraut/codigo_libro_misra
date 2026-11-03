// CH05-E19. Receptor de riesgo: no ejecutar con version incorrecta.
#include <array>
#include <cstdint>

namespace receptor_riesgo {
using Trama = std::array<std::uint8_t, 8U>;

class Receptor {
public:
    bool recibir(Trama const& trama) noexcept
    {
        std::uint16_t lectura;
        if (trama[1U] == 1U)
        {
            lectura = static_cast<std::uint16_t>(
                (static_cast<std::uint32_t>(trama[5U]) << 8U) |
                static_cast<std::uint32_t>(trama[4U]));
        }

        if ((trama[0U] == 0xA5U) && registrar(lectura))
        {
            ultimo_ = lectura;
            return true;
        }
        return false;
    }

    std::uint16_t ultimo() const noexcept { return ultimo_; }
    std::uint32_t contador() const noexcept { return contador_; }

private:
    bool registrar(std::uint16_t lectura) noexcept
    {
        ++contador_;
        return lectura < 60000U;
    }

    std::uint16_t ultimo_{0U};
    std::uint32_t contador_{0U};
};
} // namespace receptor_riesgo
