// CH05-E23. Solucion: validar, actualizar y despues decidir.
#include <cstdint>

namespace taller_solucion {
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
    if (!dato_valido)
    {
        return false;
    }
    if (!registro.habilitado())
    {
        return false;
    }

    std::uint16_t const dato_confirmado{dato};
    bool const umbral_alcanzado = registro.anotar(dato_confirmado);
    return umbral_alcanzado;
}
} // namespace taller_solucion
