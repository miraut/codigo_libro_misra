#include "../ejemplos/CH05-E16.cpp"
#include <cassert>
#include <initializer_list>
int main() {
for(bool a: {false,true}) assert(asignacion_condicional::version_compacta(a) == asignacion_condicional::version_explicita(a));
}
