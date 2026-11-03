// CH01-E11. Fragmento para revisar; las rutas problemáticas no deben ejecutarse.
#include <cstddef>
#include <cstdint>

std::uint32_t procesar_periodos(std::size_t cantidad,
                                std::uint32_t const* periodos)
{
    std::uint32_t frecuencias[cantidad];

    for (std::size_t indice{0U}; indice < cantidad; ++indice)
    {
        frecuencias[indice] = 1'000'000U / periodos[indice];
    }

    return cantidad == 0U ? 0U : frecuencias[cantidad - 1U];
}
