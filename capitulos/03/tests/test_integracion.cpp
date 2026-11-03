#include "medidas.hpp"

#include <array>
#include <cstdint>

int main()
{
    using supervision::EstadoMedida;
    using supervision::Muestra;
    std::array<Muestra, 6> const entradas{
        Muestra{0U, 0U}, Muestra{1U, 200U}, Muestra{2U, 200U},
        Muestra{3U, 65535U}, Muestra{4U, 23U}, Muestra{255U, 50U}};
    std::array<EstadoMedida, 6> const estados{
        EstadoMedida::valida, EstadoMedida::valida, EstadoMedida::valida,
        EstadoMedida::valida, EstadoMedida::canal_invalido,
        EstadoMedida::canal_invalido};
    std::array<std::uint32_t, 6> const valores{
        0U, 5000U, 5000U, 1638375U, 0U, 0U};

    for (std::size_t indice{0U}; indice < entradas.size(); ++indice)
    {
        auto const resultado{supervision::convertir(entradas[indice])};
        if (resultado.estado != estados[indice] ||
            resultado.microvoltios != valores[indice])
        {
            return 1;
        }
    }
    auto const valida{supervision::convertir(entradas[1])};
    if (!supervision::necesita_alerta(valida, 4999U))
    {
        return 2;
    }
    if (supervision::necesita_alerta(valida, 5000U))
    {
        return 3;
    }
    if (supervision::necesita_alerta(supervision::convertir(entradas[4]), 0U))
    {
        return 4;
    }
    return 0;
}
