// CH08-E09. Interfaz antigua con facilidades de <cstdarg> restringidas.
#include <cstdarg>
#include <cstdint>

std::uint32_t sumar_argumentos(std::uint32_t cantidad, ...)
{
    va_list argumentos;
    va_start(argumentos, cantidad);

    std::uint32_t suma{0U};
    for (std::uint32_t indice{0U}; indice < cantidad; ++indice)
    {
        suma += va_arg(argumentos, unsigned int);
    }

    va_end(argumentos);
    return suma;
}
