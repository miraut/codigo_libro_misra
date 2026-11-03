// CH14-E20. Propagación explícita de un resultado y conservación del ámbito.
#include <cstdint>
#include <string_view>

namespace recepcion
{
enum class EstadoLectura
{
    correcto,
    identificador_invalido
};

EstadoLectura interpretar_identificador(std::string_view texto,
                                       std::uint16_t& identificador) noexcept
{
    if (texto == "sensor")
    {
        identificador = 7U;
        return EstadoLectura::correcto;
    }
    return EstadoLectura::identificador_invalido;
}
}
