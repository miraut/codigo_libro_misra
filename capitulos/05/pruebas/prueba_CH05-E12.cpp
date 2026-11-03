#include "../ejemplos/CH05-E12.cpp"
#include <cassert>
#include <initializer_list>

namespace registro_hardware { volatile std::uint32_t registro_estado{0U}; }
int main() {
registro_hardware::registro_estado = 1U; assert(registro_hardware::hay_incidencia(false)); assert(registro_hardware::hay_incidencia_con_lectura_explicita(false)); registro_hardware::registro_estado = 0U; assert(!registro_hardware::hay_incidencia(false));
}
