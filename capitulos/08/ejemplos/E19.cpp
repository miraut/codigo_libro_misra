// CH08-E19. La lambda almacena los datos que necesitará después.
#include <array>
#include <cstdint>
#include <functional>
#include <optional>
#include <utility>

struct TramaCan
{
    std::uint32_t identificador;
    std::array<std::uint8_t, 8U> datos;
};

class Programador
{
public:
    void registrar(std::function<bool()> trabajo)
    {
        trabajo_ = std::move(trabajo);
    }

    std::optional<bool> ejecutar()
    {
        if (!trabajo_)
        {
            return std::nullopt;
        }

        return trabajo_();
    }

private:
    std::function<bool()> trabajo_{};
};

void programar_comprobacion(Programador& programador, TramaCan trama)
{
    auto trabajo = [trama]() noexcept {
        return trama.identificador <= 2047U;
    };

    programador.registrar(std::move(trabajo));
}
