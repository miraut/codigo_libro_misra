// CH08-E01. Diseño problemático: una lambda conserva una referencia local.
#include <array>
#include <cstdint>
#include <functional>
#include <utility>

struct TramaCan
{
    std::uint32_t identificador;
    std::array<std::uint8_t, 8U> datos;
};

class Programador
{
public:
    void registrar(std::function<std::uint32_t()> trabajo)
    {
        trabajo_ = std::move(trabajo);
    }

    std::uint32_t ejecutar()
    {
        return trabajo_();
    }

private:
    std::function<std::uint32_t()> trabajo_{};
};

void preparar_retransmision(Programador& programador, TramaCan trama)
{
    auto trabajo = [&trama]() noexcept {
        return trama.identificador;
    };

    programador.registrar(std::move(trabajo));
}
