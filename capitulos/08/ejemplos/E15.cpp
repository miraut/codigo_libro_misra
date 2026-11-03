// CH08-E15. Problemático: el intermediario fuerza el tratamiento rvalue.
#include <string>
#include <utility>

void guardar_mensaje(std::string const& mensaje);
void guardar_mensaje(std::string&& mensaje);

template<typename Tipo>
void remitir_mensaje(Tipo&& mensaje)
{
    guardar_mensaje(std::move(mensaje));
}
