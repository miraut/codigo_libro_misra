// Pruebas de rutas con comportamiento definido del capitulo 1.
// Estas pruebas no acreditan conformidad MISRA del conjunto.
#include <cassert>
#include <cstdint>

#include "../ejemplos/E02_validacion_del_periodo.cpp"
#include "../ejemplos/E04_lote_capacidad_fija.cpp"
#include "../ejemplos/E05_orden_de_argumentos.cpp"
#include "../ejemplos/E07_consulta_actual.cpp"
#include "../ejemplos/E09_analisis_integrado.cpp"
#include "../ejemplos/E10_premisa_de_ocho_bits.cpp"
#include "../ejemplos/E12_solucion_taller.cpp"

namespace pruebas
{
std::uint32_t consultas_reloj{0U};

std::uint32_t marca_temporal_simulada() noexcept
{
    ++consultas_reloj;
    return 4'321U;
}
}

int main()
{
    using namespace adquisicion;

    auto const sin_medida = calcular_frecuencia(0U);
    assert(sin_medida.estado == EstadoFrecuencia::sin_medida);
    assert(sin_medida.hercios == 0U);

    auto const frecuencia_normal = calcular_frecuencia(1'000U);
    assert(frecuencia_normal.estado == EstadoFrecuencia::valida);
    assert(frecuencia_normal.hercios == 1'000U);
    assert(calcular_frecuencia(65'535U).hercios == 15U);

    auto const lote_completo = preparar_muestras(32U, 0x5AU);
    assert(lote_completo.admitido);
    assert(lote_completo.cantidad == 32U);
    for (auto const valor : lote_completo.valores)
    {
        assert(valor == 0x5AU);
    }

    auto const lote_vacio = preparar_muestras(0U, 5U);
    assert(lote_vacio.admitido);
    assert(lote_vacio.cantidad == 0U);

    auto const exceso = preparar_muestras(33U, 7U);
    assert(!exceso.admitido);
    assert(exceso.cantidad == 0U);

    // C++17 permite dos ordenes en la siguiente expresion.
    // El ejemplo puede contravenir restricciones MISRA adicionales.
    auto const orden_no_fijado = construir_codigo();
    assert((orden_no_fijado == 12U) || (orden_no_fijado == 21U));
    assert(construir_codigo_ordenado() == 12U);

    assert(!hay_excepcion_pendiente());

    pruebas::consultas_reloj = 0U;
    TramaPeriodo const trama_valida{{1U, 1U, 0x03U, 0xE8U}};
    auto const resultado_valido = analizar_trama(trama_valida, pruebas::marca_temporal_simulada);
    assert(resultado_valido.estado == EstadoLectura::valida);
    assert(resultado_valido.frecuencia_hercios == 1'000U);
    assert(resultado_valido.marca_temporal_ticks == 4'321U);
    assert(pruebas::consultas_reloj == 1U);

    TramaPeriodo const trama_sin_periodo{{1U, 1U, 0U, 0U}};
    assert(analizar_trama(trama_sin_periodo, pruebas::marca_temporal_simulada).estado == EstadoLectura::sin_medida);
    assert(pruebas::consultas_reloj == 1U);

    TramaPeriodo const trama_indisponible{{1U, 0U, 0U, 0U}};
    assert(analizar_trama(trama_indisponible, pruebas::marca_temporal_simulada).estado == EstadoLectura::sin_medida);
    assert(pruebas::consultas_reloj == 1U);

    TramaPeriodo const trama_version_invalida{{2U, 1U, 0U, 1U}};
    assert(analizar_trama(trama_version_invalida, pruebas::marca_temporal_simulada).estado == EstadoLectura::trama_incorrecta);
    assert(pruebas::consultas_reloj == 1U);

    TramaPeriodo const trama_estado_invalido{{1U, 3U, 0U, 1U}};
    assert(analizar_trama(trama_estado_invalido, pruebas::marca_temporal_simulada).estado == EstadoLectura::trama_incorrecta);
    assert(pruebas::consultas_reloj == 1U);

    assert(analizar_trama(trama_valida, nullptr).estado == EstadoLectura::reloj_no_disponible);
    assert(pruebas::consultas_reloj == 1U);

    TramaPeriodo const trama_maxima{{1U, 1U, 0xFFU, 0xFFU}};
    assert(analizar_trama(trama_maxima, pruebas::marca_temporal_simulada).frecuencia_hercios == 15U);
    assert(pruebas::consultas_reloj == 2U);

    TramaPeriodo const trama_minima{{1U, 1U, 0U, 1U}};
    assert(analizar_trama(trama_minima, pruebas::marca_temporal_simulada).frecuencia_hercios == 1'000'000U);
    assert(pruebas::consultas_reloj == 3U);

    std::array<std::uint32_t, capacidad_periodos> periodos{{500U, 1000U}};
    auto const proceso_correcto = procesar_periodos(periodos, 2U);
    assert(proceso_correcto.estado == EstadoProceso::correcto);
    assert(proceso_correcto.ultima_frecuencia == 1000U);
    assert(procesar_periodos(periodos, 0U).estado == EstadoProceso::sin_periodos);
    assert(procesar_periodos(periodos, 9U).estado == EstadoProceso::capacidad_superada);
    periodos[1] = 0U;
    assert(procesar_periodos(periodos, 2U).estado == EstadoProceso::periodo_ausente);
}
