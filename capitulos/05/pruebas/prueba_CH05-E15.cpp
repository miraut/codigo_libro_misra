#include "../ejemplos/CH05-E15.cpp"
#include <cassert>
#include <initializer_list>
int main() {
desplazamiento_derecha::Historia a{{1U,2U,3U,4U,5U,6U}}; desplazamiento_derecha::dejar_espacio_al_principio(a); assert((a == desplazamiento_derecha::Historia{{1U,1U,2U,3U,4U,6U}}));
}
