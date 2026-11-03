#include "../ejemplos/E02.cpp"

int main()
{
    // El resultado de ambas llamadas es 10 debido a la continuacion de linea.
    if (supervision::clasificar(true) != 10U)
    {
        return 1;
    }
    if (supervision::clasificar(false) != 10U)
    {
        return 2;
    }
    return 0;
}
