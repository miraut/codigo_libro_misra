// CH09-E08. Problemático: la segunda operación se ejecuta siempre.
#include <cstdint>

namespace ejemplo_logico_problematico
{
class Confirmacion
{
public:
    explicit Confirmacion(bool aceptada) noexcept : aceptada_{aceptada} {}

    bool aceptada() const noexcept
    {
        return aceptada_;
    }

private:
    bool aceptada_;
};

Confirmacion operator&&(Confirmacion primera,
                        Confirmacion segunda) noexcept
{
    return Confirmacion{primera.aceptada() && segunda.aceptada()};
}

Confirmacion comprobar_autorizacion() noexcept
{
    return Confirmacion{false};
}

Confirmacion registrar_intento(std::uint32_t& intentos) noexcept
{
    ++intentos;
    return Confirmacion{true};
}

bool ejecutar(std::uint32_t& intentos) noexcept
{
    auto const resultado = comprobar_autorizacion() && registrar_intento(intentos);
    return resultado.aceptada();
}
}
