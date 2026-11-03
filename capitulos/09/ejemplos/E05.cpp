// CH09-E05. Problemático: la especialización explícita queda desplazada.
namespace ejemplo_especializacion
{
enum class Ruta
{
    generica,
    especializacion,
    puntero
};

template<typename Tipo>
Ruta seleccionar(Tipo) noexcept
{
    return Ruta::generica;
}

template<>
Ruta seleccionar<char const*>(char const*) noexcept
{
    return Ruta::especializacion; // Incumple Rule 17.8.1.
}

template<typename Tipo>
Ruta seleccionar(Tipo const*) noexcept
{
    return Ruta::puntero;
}

Ruta comprobar() noexcept
{
    char const* const texto = "sensor";
    return seleccionar(texto); // Selecciona la plantilla de punteros.
}
}
