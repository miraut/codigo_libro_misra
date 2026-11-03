#ifndef SUPERVISION_REGISTRO_HPP
#define SUPERVISION_REGISTRO_HPP

#include <cstdint>

namespace supervision
{
using IdRegistro = std::uint16_t;

struct ResultadoRegistro
{
    bool valido;
    std::uint32_t total;
};

class Registro
{
public:
    ResultadoRegistro contar(IdRegistro id) noexcept;

private:
    std::uint32_t registros_procesados_{0U};
};

ResultadoRegistro cliente_a(Registro& registro) noexcept;
ResultadoRegistro cliente_b(Registro& registro) noexcept;
}

#endif
