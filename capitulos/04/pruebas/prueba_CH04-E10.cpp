#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E10.cpp"
int main()
{
    assert(sobrecargas::enviar_contador(std::uint16_t{7U})==sobrecargas::Destino::entero_sin_signo); assert(sobrecargas::enviar(std::uint16_t{7U})==sobrecargas::Destino::entero_con_signo);
    return 0;
}
