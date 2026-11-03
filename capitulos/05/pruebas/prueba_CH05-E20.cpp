#include "../ejemplos/CH05-E20.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace receptor_robusto;
Trama t{{0xA5U,1U,2U,1U,0x34U,0x12U,10U,0U}};
for(std::size_t i=0U; i<7U; ++i) t[7U] = static_cast<std::uint8_t>(t[7U] ^ t[i]);
Resultado r{decodificar(t)}; assert(r.correcto()); assert(r.muestra.canal==2U); assert(r.muestra.lectura==0x1234U);
Controlador c{}; assert(c.recibir(t)); assert(c.ultima().lectura==0x1234U); assert(c.aceptadas()==1U); assert(c.ocupacion()==1U); assert(c.siguiente()==1U);
auto const accepted = c.aceptadas(); auto const last = c.ultima().lectura; auto const next = c.siguiente();
for (std::size_t pos = 0U; pos < 7U; ++pos) {
    Trama incorrecta = t; incorrecta[pos] ^= 0x01U;
    /* Solo se exige rechazo cuando el cambio invalida marca, version, checksum, etc. */
    if(!decodificar(incorrecta).correcto()) { assert(!c.recibir(incorrecta)); assert(c.aceptadas()==accepted); assert(c.ultima().lectura==last); assert(c.siguiente()==next); }
}
Trama marca=t; marca[0U]=0U; assert(decodificar(marca).error==Error::marca);
Trama version=t; version[1U]=2U; assert(decodificar(version).error==Error::version);
Trama canal=t; canal[2U]=4U; assert(decodificar(canal).error==Error::canal);
Trama indicadores=t; indicadores[3U]=0x80U; assert(decodificar(indicadores).error==Error::indicadores);
Trama periodo=t; periodo[6U]=0U; assert(decodificar(periodo).error==Error::periodo);
Trama comprobacion=t; comprobacion[7U]^=0x01U; assert(decodificar(comprobacion).error==Error::comprobacion);
for (int i=0; i<5; ++i) {assert(c.recibir(t));} assert(c.ocupacion()==4U); assert(c.aceptadas()==6U); assert(c.siguiente()==2U);
}
