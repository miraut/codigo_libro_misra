#include "../ejemplos/CH05-E21.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace salida_controlada; Lectura datos{3U,7U}; Trama mal{{0U,2U,5U}}; assert(!intentar_decodificar(mal,datos)); assert(datos.canal==3U && datos.valor==7U); Trama bien{{0xA5U,1U,91U}}; assert(intentar_decodificar(bien,datos)); assert(datos.canal==1U && datos.valor==91U);
}
