// CH09-E11. Un método expresa la consulta del identificador.
#include <cstdint>

namespace ejemplo_direccion_corregido
{
class Registro
{
public:
    explicit Registro(std::uint32_t identificador) noexcept
        : identificador_{identificador} {}

    std::uint32_t identificador() const noexcept
    {
        return identificador_;
    }

private:
    std::uint32_t identificador_;
};

Registro const* obtener_direccion(Registro const& registro) noexcept
{
    return &registro;
}
}
