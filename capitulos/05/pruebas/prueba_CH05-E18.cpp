#include "../ejemplos/CH05-E18.cpp"
#include <cassert>
#include <initializer_list>
int main() {
std::uint32_t a{5U}; std::uint32_t b{5U}; assert(operador_coma::calculo_compacto(a) == 16U); assert(operador_coma::calculo_explicito(b) == 16U); assert(a==b && a==6U); assert(operador_coma::suma(2U,3U)==5U);
}
