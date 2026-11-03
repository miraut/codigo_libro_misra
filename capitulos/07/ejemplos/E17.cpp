// CH07-E17. Cola acotada por valor. C++17.
#include <array>
#include <cstddef>
#include <cstdint>

namespace adquisicion
{
struct Trama
{
    std::uint32_t numero{0U};
    std::array<std::uint8_t, 8U> datos{};
};

class ColaTramas
{
public:
    bool insertar(Trama const& trama) noexcept
    {
        if (ocupacion_ == capacidad_) {
            return false;
        }

        const std::size_t posicion{
            (primero_ + ocupacion_) % capacidad_};
        elementos_[posicion] = trama;
        ++ocupacion_;
        return true;
    }

    bool extraer(Trama& destino) noexcept
    {
        if (ocupacion_ == 0U) {
            return false;
        }

        destino = elementos_[primero_];
        primero_ = (primero_ + 1U) % capacidad_;
        --ocupacion_;
        return true;
    }

private:
    static constexpr std::size_t capacidad_{4U};
    std::array<Trama, capacidad_> elementos_{};
    std::size_t primero_{0U};
    std::size_t ocupacion_{0U};
};

bool adquirir(ColaTramas& cola, std::uint32_t numero) noexcept
{
    Trama temporal{};
    temporal.numero = numero;
    temporal.datos[0U] = 0x2AU;
    return cola.insertar(temporal);
}
}
