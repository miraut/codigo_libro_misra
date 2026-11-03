// CH09-E06. La variante específica participa en la sobrecarga.
namespace ejemplo_sobrecarga
{
enum class Ruta
{
    generica,
    texto,
    puntero
};

template<typename Tipo>
Ruta seleccionar(Tipo) noexcept
{
    return Ruta::generica;
}

template<typename Tipo>
Ruta seleccionar(Tipo const*) noexcept
{
    return Ruta::puntero;
}

Ruta seleccionar(char const*) noexcept
{
    return Ruta::texto;
}

Ruta comprobar() noexcept
{
    char const* const texto = "sensor";
    return seleccionar(texto);
}
}
