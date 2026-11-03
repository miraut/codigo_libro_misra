// CH10-E12. Consultar errno en una frontera de compatibilidad documentada.
#include <cerrno>
#include <cstdint>

extern "C" int leer_canal_externo() noexcept;

namespace ejemplo_errno
{
enum class EstadoLectura : std::uint8_t
{
    correcta,
    fallo_con_codigo,
    fallo_sin_codigo
};

struct DiagnosticoLectura
{
    EstadoLectura estado;
    int codigo_externo;
};

DiagnosticoLectura consultar_canal() noexcept
{
    errno = 0;
    int const resultado = leer_canal_externo();
    int const codigo_recibido = errno;

    if (resultado != -1)
    {
        return {EstadoLectura::correcta, 0};
    }
    if (codigo_recibido == 0)
    {
        return {EstadoLectura::fallo_sin_codigo, 0};
    }
    return {EstadoLectura::fallo_con_codigo, codigo_recibido};
}
}
