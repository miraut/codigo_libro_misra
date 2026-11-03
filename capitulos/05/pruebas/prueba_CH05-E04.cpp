#include "../ejemplos/CH05-E04.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace inicializacion_condicional; assert(limite_admisible(false,false) == 0U); assert(limite_admisible(true,true) == 750U); assert(limite_admisible(false,true) == 900U);
}
