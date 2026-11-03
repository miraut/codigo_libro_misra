// CH03-E24. Archivo real del paquete: integracion_segura/diagnostico.cpp.
#include "medidas.hpp"

namespace supervision
{
bool necesita_alerta(ResultadoMedida resultado,
                    std::uint32_t umbral_microvoltios) noexcept
{
    if (resultado.estado != EstadoMedida::valida)
    {
        return false;
    }

    return resultado.microvoltios > umbral_microvoltios;
}
}
