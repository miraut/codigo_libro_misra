#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E25.cpp"
int main()
{
    bloqueo::Contador c; c.sumar(); // No llamar a sumar_incorrectamente() en el test.
    return 0;
}
