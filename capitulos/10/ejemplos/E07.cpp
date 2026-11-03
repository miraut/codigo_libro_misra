// CH10-E07. Problemático: el constructor consulta un miembro tras fallar.
#include <cstdint>

namespace ejemplo_construccion
{
struct ErrorInicializacion {};

std::uint32_t configurar_canal(bool disponible)
{
    if (!disponible)
    {
        throw ErrorInicializacion{};
    }
    return 8U;
}

class Canal
{
public:
    explicit Canal(bool disponible)
    try : identificador_{configurar_canal(disponible)}
    {
    }
    catch (ErrorInicializacion const&)
    {
        (void)identificador_; // Problemático: referencia a un miembro.
        throw;
    }

private:
    std::uint32_t identificador_{0U};
};
}
