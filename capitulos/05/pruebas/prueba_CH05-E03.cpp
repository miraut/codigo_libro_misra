#include "../ejemplos/CH05-E03.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace resultado_valido; assert(!medir(false,15U).has_value()); assert(!medir(true,2001U).has_value()); assert(medir(true,0U).value() == 0U); assert(obtener_o_conservar(false,20U,37U) == 37U);
}
