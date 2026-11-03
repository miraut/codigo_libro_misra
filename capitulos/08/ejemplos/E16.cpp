// CH08-E16. La plantilla preserva la categoría de valor recibida.
#include <cstdint>
#include <string>
#include <utility>

struct RegistroMensajes
{
    std::string ultimo{};
    std::uint32_t rutas_de_copia{0U};
    std::uint32_t rutas_de_movimiento{0U};
};

void guardar_mensaje(RegistroMensajes& registro,
                     std::string const& mensaje)
{
    registro.ultimo = mensaje;
    ++registro.rutas_de_copia;
}

void guardar_mensaje(RegistroMensajes& registro,
                     std::string&& mensaje)
{
    registro.ultimo = std::move(mensaje);
    ++registro.rutas_de_movimiento;
}

template<typename Tipo>
void remitir_mensaje(RegistroMensajes& registro, Tipo&& mensaje)
{
    guardar_mensaje(registro, std::forward<Tipo>(mensaje));
}
