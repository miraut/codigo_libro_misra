// CH08-E10. Registro de eventos mediante datos tipados y capacidad fija.
#include <array>
#include <cstddef>
#include <cstdint>

enum class ClaseEvento : std::uint8_t
{
    calibracion,
    comunicacion
};

struct EventoTelemetria
{
    ClaseEvento clase;
    std::uint32_t identificador;
    std::uint32_t codigo;
};

class RegistroTelemetria
{
public:
    bool guardar(EventoTelemetria const& evento) noexcept
    {
        if (cantidad_ == eventos_.size())
        {
            return false;
        }

        eventos_[cantidad_] = evento;
        ++cantidad_;
        return true;
    }

    std::size_t cantidad() const noexcept
    {
        return cantidad_;
    }

private:
    std::array<EventoTelemetria, 8U> eventos_{};
    std::size_t cantidad_{0U};
};
