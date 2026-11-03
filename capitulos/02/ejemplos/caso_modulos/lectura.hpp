#ifndef CH02_LECTURA_HPP
#define CH02_LECTURA_HPP

#include <array>
#include <cstddef>
#include <cstdint>

namespace caso_modulos
{
using Muestras = std::array<std::uint16_t, 4>;

// Precondicion: indice < muestras.size().
std::uint16_t leer_sin_validacion(Muestras const& muestras,
                                  std::size_t indice) noexcept;

// Esta llamada no demuestra su precondicion: intencionadamente problematica.
bool atender_solicitud_sin_validar(Muestras const& muestras,
                                  std::size_t indice,
                                  std::uint16_t& salida) noexcept;

// Alternativa: valida el indice antes de invocar a la funcion interna.
bool atender_solicitud_validada(Muestras const& muestras,
                               std::size_t indice,
                               std::uint16_t& salida) noexcept;
}
#endif
