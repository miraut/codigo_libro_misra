// CH12-E06. El contador pertenece a un objeto recibido explícitamente.
#include <cstdint>

namespace ejemplo_contador_explicito
{
class GeneradorNumeros
{
public:
    bool siguiente(std::uint32_t& numero) noexcept
    {
        if (ultimo_numero_ == 100000U)
        {
            return false;
        }

        ++ultimo_numero_;
        numero = ultimo_numero_;
        return true;
    }

private:
    std::uint32_t ultimo_numero_{0U};
};
}
