// CH14-E07. Indicadores de capacidad fija con valores bool ordinarios.
#include <array>
#include <cstddef>

namespace diagnostico
{
class Indicadores
{
public:
    bool establecer(std::size_t indice, bool activo) noexcept
    {
        if (indice >= avisos_.size())
        {
            return false;
        }
        avisos_[indice] = activo;
        return true;
    }

    bool consultar(std::size_t indice, bool& activo) const noexcept
    {
        if (indice >= avisos_.size())
        {
            return false;
        }
        activo = avisos_[indice];
        return true;
    }

private:
    std::array<bool, 8U> avisos_{};
};
}
