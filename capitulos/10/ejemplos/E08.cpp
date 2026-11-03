// CH10-E08. Movimiento e intercambio con operaciones no lanzadoras.
#include <array>
#include <cstdint>
#include <utility>

namespace ejemplo_movimiento
{
class BloqueDiagnostico
{
public:
    BloqueDiagnostico() noexcept = default;
    BloqueDiagnostico(BloqueDiagnostico&&) noexcept = default;
    BloqueDiagnostico& operator=(BloqueDiagnostico&&) noexcept = default;
    ~BloqueDiagnostico() noexcept = default;

    friend void swap(BloqueDiagnostico& primero,
                     BloqueDiagnostico& segundo) noexcept
    {
        using std::swap;
        swap(primero.datos_, segundo.datos_);
    }

private:
    std::array<std::uint8_t, 8U> datos_{};
};
}
