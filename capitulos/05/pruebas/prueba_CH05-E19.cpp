#include "../ejemplos/CH05-E19.cpp"
#include <cassert>
#include <initializer_list>
int main() {
receptor_riesgo::Receptor r{}; receptor_riesgo::Trama t{{0xA5U,1U,1U,0U,10U,0U,3U,0U}}; assert(r.recibir(t)); assert(r.ultimo() == 10U); assert(r.contador() == 1U);
}
