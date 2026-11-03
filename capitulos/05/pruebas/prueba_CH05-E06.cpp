#include "../ejemplos/CH05-E06.cpp"
#include <cassert>
#include <initializer_list>
int main() {
std::uint8_t a[2]{5U,6U}; assert(niveles_const::observar(a) == 5U); niveles_const::sustituir_primero(a,9U); assert(niveles_const::leer_con_referencia(a[0]) == 9U);
}
