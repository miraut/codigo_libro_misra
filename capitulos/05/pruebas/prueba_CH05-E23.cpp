#include "../ejemplos/CH05-E23.cpp"
#include <cassert>
#include <initializer_list>
int main() {
taller_solucion::Registro r{}; assert(!taller_solucion::confirmar(false,7U,r)); assert(r.cantidad()==0U); assert(!taller_solucion::confirmar(true,0U,r)); assert(r.cantidad()==1U); assert(taller_solucion::confirmar(true,10U,r)); assert(r.cantidad()==2U); assert(taller_solucion::confirmar(true,12U,r)); assert(r.cantidad()==3U); r.configurar(false); assert(!taller_solucion::confirmar(true,5U,r)); assert(r.cantidad()==3U);
}
