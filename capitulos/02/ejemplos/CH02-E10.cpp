// CH02-E10. Declaraciones locales al módulo sin usuarios.
#include <cstdint>

namespace
{
struct FormatoAnterior
{
    std::uint16_t identificador;
};

void transformar_formato_anterior() noexcept
{
}
}

class ProcesadorDiagnostico
{
public:
    void iniciar() noexcept {}

private:
    void recuperar_configuracion_anterior() noexcept {}
};
