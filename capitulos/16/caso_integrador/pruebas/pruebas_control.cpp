#include "control.hpp"

#include <cassert>
#include <cstdint>

namespace
{
class FuenteFalsa final : public control::PuertoAdquisicion
{
public:
    FuenteFalsa(bool disponible, std::uint32_t valor) noexcept
        : disponible_ { disponible }, valor_ { valor }
    {}

    bool obtener(std::uint32_t& salida) noexcept override
    {
        llamada_ = true;
        if (!disponible_)
        {
            return false;
        }
        salida = valor_;
        return true;
    }

    bool fue_llamada() const noexcept { return llamada_; }
private:
    bool disponible_;
    std::uint32_t valor_;
    bool llamada_ { false };
};
}

int main()
{
    using control::Estado;
    using control::evaluar;

    FuenteFalsa normal { true, 1000U };
    auto const a = evaluar(normal, 1200U);
    assert(a.estado == Estado::normal);
    assert(a.valor == 1000U);

    FuenteFalsa alarma { true, 3500U };
    auto const b = evaluar(alarma, 3000U);
    assert(b.estado == Estado::alarma);
    assert(b.valor == 3500U);

    FuenteFalsa limite { true, 4095U };
    auto const c = evaluar(limite, 4095U);
    assert(c.estado == Estado::alarma);
    assert(c.valor == 4095U);

    FuenteFalsa exceso { true, 4096U };
    auto const d = evaluar(exceso, 100U);
    assert(d.estado == Estado::muestra_fuera_de_rango);

    FuenteFalsa error { false, 0U };
    auto const e = evaluar(error, 100U);
    assert(e.estado == Estado::fuente_no_disponible);

    FuenteFalsa config { true, 500U };
    auto const f = evaluar(config, 0U);
    assert(f.estado == Estado::configuracion_invalida);
    assert(!config.fue_llamada());

    FuenteFalsa config_alta { true, 500U };
    auto const g = evaluar(config_alta, 4096U);
    assert(g.estado == Estado::configuracion_invalida);
    assert(!config_alta.fue_llamada());

    control::OrigenPerfil origen;
    auto const h = evaluar(origen, 3000U);
#if defined(CH16_PERFIL_LABORATORIO)
    assert(h.estado == Estado::normal);
    assert(h.valor == 420U);
#else
    assert(h.estado == Estado::alarma);
    assert(h.valor == 3500U);
#endif
    return 0;
}
