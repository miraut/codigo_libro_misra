#include "../ejemplos/CH05-E14.cpp"
#include <cassert>
#include <initializer_list>
int main() {
desplazamiento_izquierda::Historia a{{1U,2U,3U,4U,5U,6U}}; desplazamiento_izquierda::eliminar_primera(a); assert((a == desplazamiento_izquierda::Historia{{2U,3U,4U,5U,5U,6U}}));
}
