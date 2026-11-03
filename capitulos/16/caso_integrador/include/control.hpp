#ifndef CH16_CONTROL_HPP
#define CH16_CONTROL_HPP

#include <cstdint>

namespace control
{
constexpr std::uint32_t valor_maximo { 4095U };

enum class Estado : std::uint8_t
{
    normal,
    alarma,
    configuracion_invalida,
    fuente_no_disponible,
    muestra_fuera_de_rango
};

struct Resultado
{
    Estado estado { Estado::fuente_no_disponible };
    std::uint16_t valor { 0U };
};

class PuertoAdquisicion
{
public:
    virtual ~PuertoAdquisicion() noexcept = default;
    virtual bool obtener(std::uint32_t& valor) noexcept = 0;
};

Resultado evaluar(PuertoAdquisicion& fuente,
                  std::uint16_t umbral) noexcept;

class OrigenPerfil final : public PuertoAdquisicion
{
public:
    bool obtener(std::uint32_t& valor) noexcept override;
};
}

#endif
