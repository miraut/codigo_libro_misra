#include "../ejemplos/CH05-E05.cpp"
#include <cassert>
#include <initializer_list>
int main() {
using namespace vista_trama; Trama a{{1U,2U,3U,4U,5U,6U}}; auto const h1=huella(a); assert(h1 == huella(a)); marcar_revisada(a); assert(huella(a) != h1);
}
