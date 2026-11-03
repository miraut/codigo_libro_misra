// CH11-E18. Modelo de supervisión de capacidad fija, C++17.
#include <array>
#include <cstddef>
#include <cstdint>

namespace ejemplo_control_integrado
{
enum class EstadoControl : std::uint8_t
{
    normal,
    degradado,
    fallo
};

struct EntradaCiclo
{
    bool lectura_valida{false};
    std::uint32_t temperatura{0U};
    std::uint32_t milisegundos_sin_lectura{0U};
};

struct SalidaCiclo
{
    EstadoControl estado{EstadoControl::fallo};
    bool permitir_actuacion{false};
    bool solicitar_parada{true};
};

SalidaCiclo evaluar_ciclo(EstadoControl anterior,
                         EntradaCiclo const& entrada) noexcept
{
    constexpr std::uint32_t temperatura_maxima{75U};
    constexpr std::uint32_t ausencia_maxima_ms{100U};
    EstadoControl siguiente{EstadoControl::fallo};

    switch (anterior)
    {
        case EstadoControl::normal:
            if (!entrada.lectura_valida)
            {
                if (entrada.milisegundos_sin_lectura >= ausencia_maxima_ms)
                {
                    siguiente = EstadoControl::fallo;
                }
                else
                {
                    siguiente = EstadoControl::degradado;
                }
            }
            else if (entrada.temperatura > temperatura_maxima)
            {
                siguiente = EstadoControl::fallo;
            }
            else
            {
                siguiente = EstadoControl::normal;
            }
            break;

        case EstadoControl::degradado:
            if (entrada.milisegundos_sin_lectura >= ausencia_maxima_ms)
            {
                siguiente = EstadoControl::fallo;
            }
            else if (entrada.lectura_valida &&
                     (entrada.temperatura <= temperatura_maxima))
            {
                siguiente = EstadoControl::normal;
            }
            else
            {
                siguiente = EstadoControl::degradado;
            }
            break;

        case EstadoControl::fallo:
            siguiente = EstadoControl::fallo;
            break;

        default:
            siguiente = EstadoControl::fallo;
            break;
    }

    return SalidaCiclo{
        siguiente,
        siguiente == EstadoControl::normal,
        siguiente == EstadoControl::fallo
    };
}

std::array<SalidaCiclo, 4U> evaluar_secuencia(
    std::array<EntradaCiclo, 4U> const& entradas) noexcept
{
    std::array<SalidaCiclo, 4U> salidas{};
    EstadoControl estado{EstadoControl::normal};

    for (std::size_t indice{0U}; indice < entradas.size(); ++indice)
    {
        SalidaCiclo const salida{evaluar_ciclo(estado, entradas[indice])};
        salidas[indice] = salida;
        estado = salida.estado;
    }

    return salidas;
}
}
