#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E18.cpp"
int main()
{
    std::array<std::uint8_t,3> m{{0x03U,0x02U,0xFFU}}; auto r=trama::decodificar(m); assert(r.has_value()); assert(r->magnitud==767U&&r->estado==trama::Estado::medida&&r->alarma_activa); m[0]=0x08U; assert(!trama::decodificar(m).has_value()); m[0]=0x06U; assert(!trama::decodificar(m).has_value()); m={0x02U,0x04U,0x00U}; assert(!trama::decodificar(m).has_value());
    return 0;
}
