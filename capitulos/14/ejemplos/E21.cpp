// CH14-E21. Uso restringido por MISRA: entrada/salida de la biblioteca C.
#include <cstdio>
#include <cstdint>

namespace diagnostico
{
void mostrar_contador(unsigned int contador)
{
    (void)std::printf("Muestras: %u\n", contador);
}
}
