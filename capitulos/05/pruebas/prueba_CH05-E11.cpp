#include "../ejemplos/CH05-E11.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace efectos_persistentes; RegistroAvisos a{}; RegistroAvisos b{}; assert(!comprobar_en_condicion(false,a)); assert(a.cantidad() == 0U); for(int i=0;i<3;++i){assert(comprobar_en_condicion(true,a) == comprobar_con_fases(true,b));} assert(a.cantidad()==3U); assert(b.cantidad()==3U);
}
