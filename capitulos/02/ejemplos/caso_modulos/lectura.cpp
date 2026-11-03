#include "lectura.hpp"

namespace caso_modulos
{
std::uint16_t leer_sin_validacion(Muestras const& muestras,
                                  std::size_t indice) noexcept
{
    return muestras[indice];
}
}
