#include "../ejemplos/CH05-E08.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace condiciones; assert(aceptar_sin_aclaracion(false,false,true)); assert(!aceptar_siempre_con_calibracion(false,false,true)); assert(aceptar_con_bypass_diagnostico(false,false,true)); assert(aceptar_siempre_con_calibracion(true,true,false));
}
