// Comprobaciones C++17 en rutas definidas; no implican conformidad MISRA.
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <utility>

#include "../ejemplos/E01.cpp"
#include "../ejemplos/E02.cpp"
#include "../ejemplos/E03.cpp"
#include "../ejemplos/E04.cpp"
#include "../ejemplos/E05.cpp"
#include "../ejemplos/E06.cpp"
#include "../ejemplos/E07.cpp"
#include "../ejemplos/E09.cpp"
#include "../ejemplos/E10.cpp"
#include "../ejemplos/E11.cpp"
#include "../ejemplos/E12.cpp"
#include "../ejemplos/E13.cpp"
#include "../ejemplos/E15.cpp"
#include "../ejemplos/E16.cpp"
#include "../ejemplos/E17.cpp"
#include "../ejemplos/E18.cpp"
#include "../ejemplos/E19.cpp"
#include "../ejemplos/E20.cpp"

int main() {
    { // E01: falla el contrato de la autoasignacion pero esta ruta no usa memoria invalida.
        apertura_riesgo::RegistroCierres registro{};
        {
            apertura_riesgo::ConexionBus conexion{registro, 2U};
            conexion = std::move(conexion);
            assert(conexion.canal() == 0U);
            assert(registro.cantidad == 1U);
        }
        assert(registro.cantidad == 1U);
    }
    { // E06: la autoasignacion conserva el recurso.
        apertura_corregida::RegistroCierres registro{};
        {
            apertura_corregida::ConexionBus conexion{registro, 3U};
            conexion = std::move(conexion);
            assert(conexion.canal() == 3U);
            assert(registro.cantidad == 0U);
        }
        assert(registro.cantidad == 1U);
    }
    { // E06: la transferencia tambien cambia de registro.
        apertura_corregida::RegistroCierres primero{};
        apertura_corregida::RegistroCierres segundo{};
        {
            apertura_corregida::ConexionBus destino{primero, 1U};
            apertura_corregida::ConexionBus origen{segundo, 2U};
            destino = std::move(origen);
            assert(primero.cantidad == 1U);
            assert(destino.canal() == 2U);
            assert(origen.canal() == 0U);
        }
        assert(primero.cantidad == 1U);
        assert(segundo.cantidad == 1U);
    }
    { // E02-E03: estado, validacion y copia.
        assert(invariantes::VentanaPresion::limites_validos(4U, 7U));
        assert(!invariantes::VentanaPresion::limites_validos(8U, 7U));
        invariantes::VentanaPresion ventana{4U, 7U};
        assert(ventana.contiene(6U));
        assert(!ventana.contiene(8U));
        regla_cero::TablaCalibracion a{{1U, 2U, 3U, 4U}, 5U};
        auto b=regla_cero::duplicar(a);
        assert(b.referencias[2U] == 3U && b.revision == 5U);
    }
    { // E04-E05: el recurso se libera exactamente una vez.
        gestion_ambito::RegistroExclusividad recurso{};
        { gestion_ambito::GuardiaExclusiva guardia{recurso}; assert(recurso.ocupado()); }
        assert(!recurso.ocupado());
        firmas_especiales::RegistroConcesiones registro{};
        {
            firmas_especiales::Concesion origen{registro, 5U};
            firmas_especiales::Concesion destino{std::move(origen)};
            destino = std::move(destino);
            assert(destino.identificador() == 5U);
        }
        assert(registro.devoluciones == 1U);
    }
    { // E07 E09: construccion y conversion explicita.
        construccion::CanalTermico canal{9U, 25U};
        assert(canal.codigo() == 9U && canal.periodo_ms() == 25U);
        assert(canal.errores() == 0U);
        assert(conversiones_clase::ejemplo());
        conversion_explicita_resultado::ResultadoReserva aceptada{true};
        conversion_explicita_resultado::ResultadoReserva rechazada{false};
        assert(conversion_explicita_resultado::puede_iniciar(aceptada));
        assert(!conversion_explicita_resultado::puede_iniciar(rechazada));
    }
    { // E11: mismas cantidades, valores diferentes.
        constructores_ambivalentes::TablaUmbrales por_parentesis(2U, 5U);
        constructores_ambivalentes::TablaUmbrales por_llaves{2U, 5U};
        assert(por_parentesis.cantidad() == 2U && por_parentesis.primero() == 5U);
        assert(por_llaves.cantidad() == 2U && por_llaves.primero() == 2U);
    }
    { // E12: el fallo de validacion conserva el destino.
        fabricas_umbrales::TablaUmbrales tabla{};
        assert(fabricas_umbrales::TablaUmbrales::repetir(3U, 8U, tabla));
        assert(tabla.cantidad() == 3U && tabla.primero() == 8U);
        assert(!fabricas_umbrales::TablaUmbrales::repetir(9U, 7U, tabla));
        assert(tabla.cantidad() == 3U && tabla.primero() == 8U);
        assert(fabricas_umbrales::TablaUmbrales::desde_lista({5U, 6U}, tabla));
        assert(tabla.cantidad() == 2U && tabla.primero() == 5U);
    }
    { // E13: using hace visible la sobrecarga adecuada.
        sobrecargas_heredadas::RegistroExplicito registro{};
        assert(registro.registrar(std::uint16_t{7U}) == 7U);
    }
    { // E15: resultado de despacho en constructor.
        construccion_virtual::CanalEspecial canal{};
        assert(canal.codigo_registrado() == 1U);
        assert(canal.identificar() == 7U);
    }
    { // E16: los valores por defecto siguen el tipo estatico.
        contratos_virtuales::MedidaTermica medida{};
        contratos_virtuales::InterfazMedida& interfaz=medida;
        assert(medida.calcular() == 30U);
        assert(interfaz.calcular() == 10U);
    }
    { // E17-E19: consulta sin comparacion potencialmente virtual ni typeid.
        assert(!metodos_comparables::hay_operacion(nullptr));
        assert(metodos_comparables::hay_operacion(&metodos_comparables::Unidad::iniciar));
        conversion_virtual::CanalLocal local{};
        conversion_virtual::CanalRemoto remoto{};
        conversion_virtual::InterfazCanal* p_local=&local;
        conversion_virtual::InterfazCanal* p_remoto=&remoto;
        assert(conversion_virtual::es_local(p_local));
        assert(!conversion_virtual::es_local(p_remoto));
        identificacion_dinamica::CanalRemoto remoto2{};
        assert(identificacion_dinamica::consulta_por_interfaz(remoto2));
    }
    { // E20: integracion, autoasignacion, error que conserva salida, liberacion.
        caso_adquisicion::BancoCanales banco{};
        caso_adquisicion::OrigenFijo origen{17U};
        caso_adquisicion::PerfilAdquisicion perfil{20U, 40U};
        assert(caso_adquisicion::perfil_valido(perfil));
        assert(!caso_adquisicion::perfil_valido({0U, 10U}));
        {
            caso_adquisicion::ReservaCanal reserva{banco, 2U};
            assert(reserva.activa());
            caso_adquisicion::ReservaCanal duplicada{banco, 2U};
            caso_adquisicion::ReservaCanal fuera_de_rango{banco, 8U};
            assert(!duplicada.activa());
            assert(!fuera_de_rango.activa());
            reserva = std::move(reserva);
            assert(reserva.activa());
            caso_adquisicion::UnidadAdquisicion unidad{origen, std::move(reserva), perfil};
            std::uint16_t resultado{0U};
            assert(unidad.adquirir(resultado));
            assert(resultado == 17U);
        }
        assert(!banco.esta_reservado(2U));
        {
            caso_adquisicion::ReservaCanal reserva{banco, 1U};
            assert(reserva.activa());
            caso_adquisicion::PerfilAdquisicion perfil_estrecho{20U, 10U};
            caso_adquisicion::UnidadAdquisicion unidad{origen, std::move(reserva), perfil_estrecho};
            std::uint16_t resultado{99U};
            assert(!unidad.adquirir(resultado));
            assert(resultado == 99U);
        }
        assert(!banco.esta_reservado(1U));
    }
}
