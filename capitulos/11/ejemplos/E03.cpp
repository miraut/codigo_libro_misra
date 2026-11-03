// CH11-E03. El else se asocia al if interno.
namespace ejemplo_asociacion_else
{
struct Indicadores
{
    bool autorizado{false};
    bool incidencia{false};
};

void evaluar(bool dispositivo_habilitado,
             bool condicion_segura,
             Indicadores& indicadores) noexcept
{
    if (dispositivo_habilitado)
        if (condicion_segura)
            indicadores.autorizado = true;
    else
        indicadores.incidencia = true;
}
}
