// CH03-E25. Archivo real del paquete: integracion_segura/prueba_integracion.cpp.
#include "medidas.hpp"

#include <cassert>
#include <cstdint>

int main()
{
    using supervision::EstadoMedida;
    using supervision::Muestra;

    auto const medida{supervision::convertir(Muestra{2U, 200U})};
    assert(medida.estado == EstadoMedida::valida);
    assert(medida.microvoltios == 5000U);
    assert(supervision::necesita_alerta(medida, 4500U));
    assert(!supervision::necesita_alerta(medida, 5000U));

    auto const invalida{supervision::convertir(Muestra{4U, 200U})};
    assert(invalida.estado == EstadoMedida::canal_invalido);
    assert(invalida.microvoltios == 0U);
    assert(!supervision::necesita_alerta(invalida, 0U));
}
