// CH03-E23. Archivo real del paquete: integracion_segura/conversion.cpp.
#include "medidas.hpp"

namespace supervision
{
namespace
{
constexpr IdCanal numero_canales{4U};
constexpr std::uint32_t escala_microvoltios{25U};
}

ResultadoMedida convertir(Muestra muestra) noexcept
{
    if (muestra.canal >= numero_canales)
    {
        return ResultadoMedida{EstadoMedida::canal_invalido, 0U};
    }

    return ResultadoMedida{
        EstadoMedida::valida,
        static_cast<std::uint32_t>(muestra.valor) * escala_microvoltios};
}
}
