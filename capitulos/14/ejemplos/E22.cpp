// CH14-E22. Uso problemático: lectura tras escritura sin reposicionamiento.
#include <fstream>
#include <string>

namespace registro
{
void escribir_y_leer_sin_posicionar(std::string const& ruta)
{
    std::fstream archivo{ruta,
        std::ios::in | std::ios::out | std::ios::trunc};
    archivo << "OK\n" << std::flush;
    std::string linea{};
    (void)std::getline(archivo, linea);
}
}
