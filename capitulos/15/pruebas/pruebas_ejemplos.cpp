// Pruebas de ejemplos seguros: se usan los codigos originales como unidades.
#include "../ejemplos/E04_resultado_explicito.cpp"
#include "../ejemplos/E06_indice_comprobado.cpp"
#include "../ejemplos/E08_sincronizacion_atomica.cpp"
#include "../ejemplos/E09_suma_protegida.cpp"
#include <array>
#include <cstdint>
#include <limits>

int main()
{
    if (!comprobar_ciclos())
    {
        return 1;
    }

    std::array<std::uint16_t, 8> const canales{{2U, 4U, 6U, 8U, 10U, 12U, 14U, 16U}};
    std::uint16_t lectura{0U};
    if (!obtener_canal(canales, 7U, lectura) || (lectura != 16U))
    {
        return 2;
    }
    if (obtener_canal(canales, 8U, lectura))
    {
        return 3;
    }

    PublicacionUnica estado{};
    std::uint32_t salida{0U};
    if (consumir(estado, salida))
    {
        return 4;
    }
    publicar(estado, 77U);
    if (!consumir(estado, salida) || (salida != 77U))
    {
        return 5;
    }

    std::uint32_t suma{0U};
    if (!acumular_sin_desbordamiento(20U, 7U, suma) || (suma != 27U))
    {
        return 6;
    }
    if (acumular_sin_desbordamiento(
            std::numeric_limits<std::uint32_t>::max(), 1U, suma))
    {
        return 7;
    }
    return 0;
}
