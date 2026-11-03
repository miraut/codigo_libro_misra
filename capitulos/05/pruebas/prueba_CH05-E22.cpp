#include "../ejemplos/CH05-E22.cpp"
#include <cassert>
#include <initializer_list>
int main() {
taller_riesgo::Registro r{}; assert(!taller_riesgo::confirmar(true,0U,r)); assert(r.cantidad()==1U); assert(taller_riesgo::confirmar(true,7U,r)); assert(r.cantidad()==2U); r.configurar(false); assert(!taller_riesgo::confirmar(false,7U,r)); assert(r.cantidad()==2U); /* No ejecutar valido=false y habilitado=true */
}
