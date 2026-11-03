// Pruebas de codigo seguro, C++17. Ejemplos problemáticos E01, E05 y E12 no se ejecutan.
#include "../ejemplos/E02.cpp"
#include "../ejemplos/E03.cpp"
#include "../ejemplos/E04.cpp"
#include "../ejemplos/E06.cpp"
#include "../ejemplos/E07.cpp"
#include "../ejemplos/E08.cpp"
#include "../ejemplos/E09.cpp"
#include "../ejemplos/E10.cpp"
#include "../ejemplos/E11.cpp"
#include "../ejemplos/E13.cpp"
#include "../ejemplos/E14.cpp"
#include "../ejemplos/E15.cpp"

#include <cassert>
#include <cstdint>
#include <string_view>
#include <thread>

void comprobar_orden_y_periferico()
{
    auto const resultado{ejemplo_argumentos::construir_ordenado()};
    assert(resultado.primero == 1U);
    assert(resultado.segundo == 2U);

    struct Registros
    {
        volatile std::uint32_t a{3U};
        volatile std::uint32_t b{4U};
    } registros{};
    assert(ejemplo_dos_registros::sumar_con_orden(registros.a, registros.b) == 7U);

    ejemplo_periferico::RegistrosAdquisicion periferico{};
    periferico.estado = 0U;
    periferico.dato = 71U;
    assert(!ejemplo_periferico::leer_dispositivo(periferico).disponible);
    periferico.estado = 1U;
    auto const lectura{ejemplo_periferico::leer_dispositivo(periferico)};
    assert(lectura.disponible);
    assert(lectura.valor == 71U);
}

void comprobar_estado_explicito()
{
    ejemplo_contador_explicito::GeneradorNumeros generador{};
    std::uint32_t numero{0U};
    assert(generador.siguiente(numero));
    assert(numero == 1U);
    assert(generador.siguiente(numero));
    assert(numero == 2U);
}

void comprobar_bandeja_concurrencia()
{
    ejemplo_bandeja::BandejaMuestras bandeja{};
    constexpr std::uint32_t cantidad{1500U};
    std::thread productor{[&bandeja]()
    {
        for (std::uint32_t indice{1U}; indice <= cantidad;)
        {
            if (bandeja.publicar({indice, indice * 2U}))
            {
                ++indice;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }};
    std::thread consumidor{[&bandeja]()
    {
        ejemplo_bandeja::Muestra muestra{};
        for (std::uint32_t esperado{1U}; esperado <= cantidad;)
        {
            if (bandeja.retirar(muestra))
            {
                assert(muestra.secuencia == esperado);
                assert(muestra.valor == esperado * 2U);
                ++esperado;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }};
    productor.join();
    consumidor.join();
}

void comprobar_atomos()
{
    ejemplo_contador_atomico::ContadorEventos contador{};
    std::thread primero{[&contador]()
    {
        for (std::uint32_t i{0U}; i < 10000U; ++i)
        {
            contador.registrar_evento();
        }
    }};
    std::thread segundo{[&contador]()
    {
        for (std::uint32_t i{0U}; i < 10000U; ++i)
        {
            contador.registrar_evento();
        }
    }};
    primero.join();
    segundo.join();
    assert(contador.consultar() == 20000U);
}

void comprobar_canal_spsc_concurrencia()
{
    ejemplo_canal_spsc::CanalUnaPosicion canal{};
    constexpr std::uint32_t cantidad{2000U};
    std::thread productor{[&canal]()
    {
        for (std::uint32_t indice{1U}; indice <= cantidad;)
        {
            if (canal.publicar({indice, indice * 3U}))
            {
                ++indice;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }};
    std::thread consumidor{[&canal]()
    {
        ejemplo_canal_spsc::Muestra muestra{};
        for (std::uint32_t esperado{1U}; esperado <= cantidad;)
        {
            if (canal.retirar(muestra))
            {
                assert(muestra.secuencia == esperado);
                assert(muestra.valor == esperado * 3U);
                ++esperado;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }};
    productor.join();
    consumidor.join();
}

void comprobar_aviso_y_conversion()
{
    ejemplo_aviso::AvisoAdquisicion aviso{};
    assert(!aviso.retirar_aviso());
    aviso.notificar_desde_tarea();
    aviso.notificar_desde_tarea();
    assert(aviso.retirar_aviso());
    assert(!aviso.retirar_aviso());

    auto const numero{ejemplo_conversion::leer_decimal("274")};
    assert(numero.has_value());
    assert(*numero == 274);
    assert(!ejemplo_conversion::leer_decimal("").has_value());
    assert(!ejemplo_conversion::leer_decimal("27a").has_value());
    assert(!ejemplo_conversion::leer_decimal("99999999999999").has_value());
    assert(ejemplo_conversion::leer_decimal("-8").value() == -8);
}

void comprobar_copia_y_fechas()
{
    ejemplo_copia_entorno::TextoCorto texto{};
    assert(ejemplo_copia_entorno::copiar_cadena("modo=normal", texto));
    assert(std::string_view{texto.data()} == "modo=normal");
    assert(!ejemplo_copia_entorno::copiar_cadena(nullptr, texto));
    assert(!ejemplo_copia_entorno::copiar_cadena(
        "Un texto de configuracion que supera los treinta y un caracteres", texto));
    assert(texto.back() == '\0');

    std::tm campos{};
    assert(ejemplo_fecha_hora::descomponer_utc(std::time_t{0}, campos));
}

void comprobar_integrador()
{
    ejemplo_adquisicion_integrada::Registros registros{};
    ejemplo_adquisicion_integrada::CanalMuestras canal{};
    ejemplo_adquisicion_integrada::Adquisidor adquisidor{registros, canal};
    registros.estado = 0U;
    registros.dato = 20U;
    assert(!adquisidor.adquirir(1U));
    registros.estado = 1U;
    assert(adquisidor.adquirir(1U));
    assert(!adquisidor.adquirir(2U));
    ejemplo_adquisicion_integrada::Muestra medida{};
    assert(canal.retirar(medida));
    assert(medida.valor == 20U);
    assert(medida.secuencia == 1U);
    assert(!canal.retirar(medida));
    registros.dato = 90U;
    assert(adquisidor.adquirir(2U));
    assert(canal.retirar(medida));
    assert(medida.valor == 90U);
}

int main()
{
    comprobar_orden_y_periferico();
    comprobar_estado_explicito();
    comprobar_bandeja_concurrencia();
    comprobar_atomos();
    comprobar_canal_spsc_concurrencia();
    comprobar_aviso_y_conversion();
    comprobar_copia_y_fechas();
    comprobar_integrador();
}
