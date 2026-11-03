#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E04.cpp"
int main()
{
    bool resultado=true; assert(logica::codificar_alarma(true)==1U); assert(logica::codificar_alarma(false)==0U); assert(logica::decodificar_alarma(0U,resultado)&&!resultado); assert(logica::decodificar_alarma(1U,resultado)&&resultado); assert(!logica::decodificar_alarma(2U,resultado)&&resultado);
    return 0;
}
