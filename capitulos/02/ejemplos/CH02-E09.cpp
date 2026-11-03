// CH02-E09. Objeto de alcance cuya construcción y destrucción son relevantes.
#include <mutex>

void actualizar_con_proteccion(std::mutex& mutex,
                               int& valor_compartido) noexcept
{
    std::lock_guard<std::mutex> proteccion{mutex};
    ++valor_compartido;
}
