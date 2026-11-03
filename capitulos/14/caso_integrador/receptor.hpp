#ifndef GUIA_MISRA_CAP14_RECEPTOR_HPP
#define GUIA_MISRA_CAP14_RECEPTOR_HPP

#include "configuracion.hpp"
#include <array>
#include <cstddef>
#include <string_view>

namespace equipo
{
// Buffer recibido por el llamador. Esta vista no se conserva tras la llamada.
template<std::size_t Capacidad>
ErrorConfiguracion procesar_bloque(
    std::array<char, Capacidad> const& datos,
    std::size_t longitud,
    Configuracion& estado) noexcept
{
    if (longitud > datos.size())
    {
        return ErrorConfiguracion::formato;
    }
    std::string_view const mensaje{datos.data(), longitud};
    return interpretar(mensaje, estado);
}
}

#endif // GUIA_MISRA_CAP14_RECEPTOR_HPP
