// CH03-E22. Archivo real del paquete: integracion_segura/medidas.hpp.
#ifndef SUPERVISION_MEDIDAS_HPP
#define SUPERVISION_MEDIDAS_HPP

#include <cstdint>

namespace supervision
{
using IdCanal = std::uint8_t;
using ValorCrudo = std::uint16_t;

struct Muestra
{
    IdCanal canal;
    ValorCrudo valor;
};

enum class EstadoMedida : std::uint8_t
{
    valida,
    canal_invalido
};

struct ResultadoMedida
{
    EstadoMedida estado;
    std::uint32_t microvoltios;
};

ResultadoMedida convertir(Muestra muestra) noexcept;
bool necesita_alerta(ResultadoMedida resultado,
                    std::uint32_t umbral_microvoltios) noexcept;
}

#endif
