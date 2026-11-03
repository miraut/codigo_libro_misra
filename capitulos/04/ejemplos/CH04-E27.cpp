// CH04-E27. Decodificación, validación de estado y aritmética con rango demostrado.
#include <array>
#include <climits>
#include <cstdint>
#include <limits>
#include <variant>

namespace integrador
{
static_assert(CHAR_BIT == 8, "Se requieren octetos de ocho bits");

enum class Estado : std::uint8_t
{
    espera = 0U,
    adquiriendo = 1U,
    detenido = 2U
};

enum class Error : std::uint8_t
{
    trama_invalida = 1U,
    medida_no_representable = 2U
};

struct ResultadoMedida
{
    Estado estado;
    std::uint32_t pulsos_corregidos;
    bool alarma;
};

using Resultado = std::variant<ResultadoMedida, Error>;

Resultado procesar(std::array<std::uint8_t, 3> const& mensaje,
                   std::int32_t correccion,
                   std::uint32_t umbral)
{
    std::uint32_t const control =
        static_cast<std::uint32_t>(mensaje[0]);
    std::uint32_t const codigo = (control >> 1U) & 0x3U;
    std::uint32_t const dato =
        (static_cast<std::uint32_t>(mensaje[1]) << 8U) |
         static_cast<std::uint32_t>(mensaje[2]);

    if (((control & 0xF8U) != 0U) || (codigo > 2U) ||
        (dato > 1023U))
    {
        return Error::trama_invalida;
    }

    std::int64_t const corregido =
        static_cast<std::int64_t>(dato) +
        static_cast<std::int64_t>(correccion);

    // dato <= 1023 y correccion es int32_t: la cota superior
    // del resultado ya cabe en uint32_t. Solo falta excluir negativos.
    if (corregido < 0)
    {
        return Error::medida_no_representable;
    }

    Estado const estado =
        static_cast<Estado>(static_cast<std::uint8_t>(codigo));
    std::uint32_t const pulsos =
        static_cast<std::uint32_t>(corregido);
    bool const alarma_recibida = (control & 0x1U) != 0U;
    bool const alarma_de_umbral = pulsos > umbral;

    return ResultadoMedida{
        estado,
        pulsos,
        alarma_recibida || alarma_de_umbral
    };
}
}
