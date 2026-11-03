// Pruebas funcionales de ejemplos seguros seleccionados, C++17.
// Las inclusiones contienen fragmentos independientes y sus cabeceras.
#include "../ejemplos/E03.cpp"
#include "../ejemplos/E04.cpp"
#include "../ejemplos/E07.cpp"
#include "../ejemplos/E09.cpp"
#include "../ejemplos/E10.cpp"
#include "../ejemplos/E11.cpp"
#include "../ejemplos/E12.cpp"
#include "../ejemplos/E13.cpp"
#include <array>
#include <cassert>
#include <cstdint>

static_assert(configuracion::periodo_muestreo_ms == 20U, "periodo incorrecto");
static_assert(supervision::resultado == 23U, "expansion de alias inesperada");
static_assert(supervision::calculo_con_macro == 8U, "resultado de macro inesperado");
static_assert(supervision::calculo_con_funcion == 10U, "resultado de funcion inesperado");
static_assert(protocolo::leer_entero_be({0x12U, 0x34U}) == 0x1234U,
              "decodificacion incorrecta");

int main()
{
    std::uint32_t contador{0U};
    assert(supervision::lectura_duplicada(contador) == 2U);
    assert(contador == 1U);
    assert(configuracion::muestra_fuera_de_rango(12U, 10U));
    assert(!configuracion::muestra_fuera_de_rango(8U, 10U));
    assert(diagnostico::describir(diagnostico::Evento::inicio)[0] == 'I');
    assert(!supervision::diagnostico_activo);
    return 0;
}
