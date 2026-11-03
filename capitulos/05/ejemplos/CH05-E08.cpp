// CH05-E08. Dos agrupaciones producen decisiones diferentes.
namespace condiciones {
bool aceptar_sin_aclaracion(bool calibrado,
                           bool activo,
                           bool diagnostico) noexcept
{
    return calibrado && activo || diagnostico;
}

bool aceptar_siempre_con_calibracion(bool calibrado,
                                    bool activo,
                                    bool diagnostico) noexcept
{
    return calibrado && (activo || diagnostico);
}

bool aceptar_con_bypass_diagnostico(bool calibrado,
                                   bool activo,
                                   bool diagnostico) noexcept
{
    return (calibrado && activo) || diagnostico;
}
} // namespace condiciones
