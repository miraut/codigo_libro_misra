#include "../ejemplos/CH05-E10.cpp"
#include <cassert>
#include <initializer_list>
int main() {
argumentos::Contador c{}; assert(argumentos::con_orden_explicito(c) == 12U); assert(c.valor == 2U);
}
