// CH14-E24. Análisis de configuración textual con resultado explícito.
#include <charconv>
#include <cstdint>
#include <string_view>
#include <system_error>

namespace equipo
{
enum class Modo
{
    activo,
    pausa
};

enum class ErrorConfiguracion
{
    ninguno,
    formato,
    version,
    periodo,
    modo
};

struct Configuracion
{
    std::uint16_t periodo_ms{20U};
    Modo modo{Modo::pausa};
};

bool analizar_decimal(std::string_view campo,
                      std::uint32_t& valor) noexcept
{
    if (campo.empty())
    {
        return false;
    }

    char const* const inicio = campo.data();
    char const* const fin = inicio + campo.size();
    auto const resultado = std::from_chars(inicio, fin, valor, 10);
    return (resultado.ec == std::errc{}) && (resultado.ptr == fin);
}

ErrorConfiguracion interpretar(std::string_view mensaje,
                              Configuracion& destino) noexcept
{
    constexpr std::string_view prefijo_version{"version="};
    constexpr std::string_view prefijo_periodo{"periodo_ms="};
    constexpr std::string_view prefijo_modo{"modo="};

    auto const primer_separador = mensaje.find(';');
    if (primer_separador == std::string_view::npos)
    {
        return ErrorConfiguracion::formato;
    }

    auto const segundo_separador = mensaje.find(';', primer_separador + 1U);
    if ((segundo_separador == std::string_view::npos) ||
        (mensaje.find(';', segundo_separador + 1U) != std::string_view::npos))
    {
        return ErrorConfiguracion::formato;
    }

    auto const campo_version = mensaje.substr(0U, primer_separador);
    auto const campo_periodo = mensaje.substr(
        primer_separador + 1U,
        segundo_separador - primer_separador - 1U);
    auto const campo_modo = mensaje.substr(segundo_separador + 1U);

    if ((campo_version.substr(0U, prefijo_version.size()) != prefijo_version) ||
        (campo_periodo.substr(0U, prefijo_periodo.size()) != prefijo_periodo) ||
        (campo_modo.substr(0U, prefijo_modo.size()) != prefijo_modo))
    {
        return ErrorConfiguracion::formato;
    }

    std::uint32_t version{0U};
    if (!analizar_decimal(campo_version.substr(prefijo_version.size()),
                          version))
    {
        return ErrorConfiguracion::formato;
    }
    if (version != 1U)
    {
        return ErrorConfiguracion::version;
    }

    std::uint32_t periodo{0U};
    if (!analizar_decimal(campo_periodo.substr(prefijo_periodo.size()),
                          periodo) ||
        (periodo < 5U) || (periodo > 1000U))
    {
        return ErrorConfiguracion::periodo;
    }

    Modo nuevo_modo{Modo::pausa};
    auto const texto_modo = campo_modo.substr(prefijo_modo.size());
    if (texto_modo == "activo")
    {
        nuevo_modo = Modo::activo;
    }
    else if (texto_modo == "pausa")
    {
        nuevo_modo = Modo::pausa;
    }
    else
    {
        return ErrorConfiguracion::modo;
    }

    Configuracion const propuesta{
        static_cast<std::uint16_t>(periodo), nuevo_modo};
    destino = propuesta;
    return ErrorConfiguracion::ninguno;
}
}
