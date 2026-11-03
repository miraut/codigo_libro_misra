// CH05-E22. Ejercicio: identificar un camino de lectura invalida.
#include <cstdint>

namespace taller_riesgo {
class Registro {
public:
    bool habilitado() const noexcept { return habilitado_; }
    void configurar(bool habilitar) noexcept { habilitado_ = habilitar; }
    std::uint32_t cantidad() const noexcept { return eventos_; }

    bool anotar(std::uint16_t dato) noexcept
    {
        ++eventos_;
        return (dato != 0U) && (eventos_ >= 2U);
    }

private:
    bool habilitado_{true};
    std::uint32_t eventos_{0U};
};

bool confirmar(bool dato_valido, std::uint16_t dato,
              Registro& registro) noexcept
{
    std::uint16_t dato_confirmado;
    if (dato_valido)
    {
        dato_confirmado = dato;
    }

    if (registro.habilitado() && registro.anotar(dato_confirmado))
    {
        return true;
    }
    return false;
}
} // namespace taller_riesgo
