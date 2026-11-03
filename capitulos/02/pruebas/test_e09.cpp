#include <cassert>
#include "../ejemplos/CH02-E09.cpp"
int main()
{
    std::mutex mutex;
    int valor{0};
    actualizar_con_proteccion(mutex, valor);
    assert(valor == 1);
}
