// CH11-E17. Retornos anticipados y cierre ligado al ámbito del objeto.
#include <array>
#include <cstdint>

namespace ejemplo_sesion
{
class SesionAdquisicion
{
public:
    explicit SesionAdquisicion(std::uint32_t& cierres) noexcept
        : cierres_{cierres}
    {
    }

    ~SesionAdquisicion() noexcept
    {
        ++cierres_;
    }

    SesionAdquisicion(SesionAdquisicion const&) = delete;
    SesionAdquisicion& operator=(SesionAdquisicion const&) = delete;

private:
    std::uint32_t& cierres_;
};

enum class ResultadoAdquisicion : std::uint8_t
{
    completada,
    canal_no_disponible,
    muestra_fuera_de_rango
};

ResultadoAdquisicion adquirir(
    bool canal_disponible,
    std::array<std::uint32_t, 3U> const& muestras,
    std::uint32_t& cierres) noexcept
{
    if (!canal_disponible)
    {
        return ResultadoAdquisicion::canal_no_disponible;
    }

    SesionAdquisicion sesion{cierres};

    for (std::uint32_t muestra : muestras)
    {
        if (muestra > 100U)
        {
            return ResultadoAdquisicion::muestra_fuera_de_rango;
        }
    }

    return ResultadoAdquisicion::completada;
}
}
