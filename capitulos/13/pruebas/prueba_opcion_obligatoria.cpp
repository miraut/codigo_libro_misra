#include "../ejemplos/E08.cpp"
#include <cassert>

int main()
{
#if EQUIPO_EN_CAMPO == 1
    assert(supervision::consultar_entrada(325U) == 325U);
#else
    assert(supervision::consultar_entrada(325U) == 0U);
#endif
    return 0;
}
