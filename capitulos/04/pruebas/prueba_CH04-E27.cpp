#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E27.cpp"
int main()
{
    std::array<std::uint8_t,3> m{{0x02U,0U,20U}}; auto r=integrador::procesar(m,-5,12U); assert(std::holds_alternative<integrador::ResultadoMedida>(r)); auto dato=std::get<integrador::ResultadoMedida>(r); assert(dato.pulsos_corregidos==15U&&dato.alarma&&dato.estado==integrador::Estado::adquiriendo); m[0]=0x08U; assert(std::get<integrador::Error>(integrador::procesar(m,0,12U))==integrador::Error::trama_invalida); m[0]=0x02U; assert(std::get<integrador::Error>(integrador::procesar(m,-100,12U))==integrador::Error::medida_no_representable); m={0x02U,4U,0U}; assert(std::get<integrador::Error>(integrador::procesar(m,0,12U))==integrador::Error::trama_invalida);
    return 0;
}
