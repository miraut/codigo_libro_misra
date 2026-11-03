#include "lectura.hpp"

namespace caso_modulos
{
bool atender_solicitud_sin_validar(Muestras const& muestras,
                                  std::size_t indice,
                                  std::uint16_t& salida) noexcept
{
    salida = leer_sin_validacion(muestras, indice);
    return true;
}

bool atender_solicitud_validada(Muestras const& muestras,
                               std::size_t indice,
                               std::uint16_t& salida) noexcept
{
    if (indice >= muestras.size())
    {
        return false;
    }
    salida = leer_sin_validacion(muestras, indice);
    return true;
}
}
