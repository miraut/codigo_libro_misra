#include <array>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

#include "../ejemplos/E03.cpp"
#include "../ejemplos/E05.cpp"
#include "../ejemplos/E07.cpp"
#include "../ejemplos/E09.cpp"
#include "../ejemplos/E11.cpp"
#include "../ejemplos/E13.cpp"
#include "../ejemplos/E16.cpp"
#include "../ejemplos/E18.cpp"
#include "../ejemplos/E20.cpp"
#include "../ejemplos/E23.cpp"

int main(int argc, char** argv)
{
    assert(argc == 2);
    {
        std::vector<std::uint16_t> tramas_recibidas{9U, 1U, 9U, 3U, 1U};
        tramas::eliminar_repeticiones(tramas_recibidas);
        assert((tramas_recibidas == std::vector<std::uint16_t>{1U, 3U, 9U}));
    }
    {
        std::vector<std::uint16_t> lecturas{1U, 50U, 200U, 10U, 201U};
        assert(medidas::retirar_invalidas(lecturas, 100U) == 2U);
        assert((lecturas == std::vector<std::uint16_t>{1U, 50U, 10U}));
    }
    {
        diagnostico::Indicadores indicadores;
        bool activo{true};
        assert(indicadores.establecer(3U, true));
        assert(indicadores.consultar(3U, activo) && activo);
        assert(!indicadores.establecer(8U, false));
        assert(!indicadores.consultar(8U, activo));
    }
    {
        using configuracion::EstadoConversion;
        assert(configuracion::leer_periodo("5").estado == EstadoConversion::correcto);
        assert(configuracion::leer_periodo("1000").periodo_ms == 1000U);
        assert(configuracion::leer_periodo("4").estado == EstadoConversion::valor_no_permitido);
        assert(configuracion::leer_periodo("2000").estado == EstadoConversion::valor_no_permitido);
        assert(configuracion::leer_periodo("").estado == EstadoConversion::formato_invalido);
        assert(configuracion::leer_periodo(" 5").estado == EstadoConversion::formato_invalido);
        assert(configuracion::leer_periodo("+5").estado == EstadoConversion::formato_invalido);
        assert(configuracion::leer_periodo("5ms").estado == EstadoConversion::formato_invalido);
        assert(configuracion::leer_periodo("99999999999999999999999").estado == EstadoConversion::fuera_de_rango);
    }
    {
        std::array<char, 12U> destino{};
        assert(diagnostico::copiar_etiqueta("canal-1", destino));
        assert(std::string(destino.data()) == "canal-1");
        assert(!diagnostico::copiar_etiqueta("abcdefghijkl", destino));
        assert(std::string(destino.data()) == "canal-1");
    }
    {
        assert(mantenimiento::tramitar(mantenimiento::Accion::consultar_estado, false)
               == mantenimiento::Resultado::aceptada);
        assert(mantenimiento::tramitar(mantenimiento::Accion::solicitar_reinicio, false)
               == mantenimiento::Resultado::no_disponible);
        assert(mantenimiento::tramitar(mantenimiento::Accion::solicitar_reinicio, true)
               == mantenimiento::Resultado::aceptada);
    }
    {
        auto const medida = protocolo::decodificar({0x12U, 0x34U, 0x00U, 0xFFU});
        assert(medida.secuencia == 0x1234U);
        assert(medida.valor == 255U);
    }
    {
        assert(protocolo::contiene_solo_digitos("0123456789"));
        assert(!protocolo::contiene_solo_digitos(""));
        assert(!protocolo::contiene_solo_digitos("12 3"));
        assert(!protocolo::contiene_solo_digitos("12x"));
    }
    {
        std::uint16_t identificador{93U};
        assert(recepcion::interpretar_identificador("sensor", identificador)
               == recepcion::EstadoLectura::correcto);
        assert(identificador == 7U);
        assert(recepcion::interpretar_identificador("otro", identificador)
               == recepcion::EstadoLectura::identificador_invalido);
        assert(identificador == 7U);
    }
    assert(registro::escribir_y_verificar(argv[1]));
    return 0;
}
