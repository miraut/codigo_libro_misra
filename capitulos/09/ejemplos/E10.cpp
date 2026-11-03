// CH09-E10. Problemático: &registro devuelve un identificador.
#include <cstdint>
#include <memory>

namespace ejemplo_direccion_problematico
{
class Registro
{
public:
    explicit Registro(std::uint32_t identificador) noexcept
        : identificador_{identificador} {}

    std::uint32_t operator&() const noexcept
    {
        return identificador_; // Incumple Rule 16.5.2.
    }

private:
    std::uint32_t identificador_;
};

std::uint32_t obtener_identificador(Registro const& registro) noexcept
{
    return &registro; // Llama al operador definido por Registro.
}

Registro const* obtener_direccion(Registro const& registro) noexcept
{
    return std::addressof(registro); // Dirección real del objeto.
}
}
