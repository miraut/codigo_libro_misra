// CH14-E23. Reposicionamiento explícito y comprobación de estado del flujo.
#include <fstream>
#include <string>

namespace registro
{
bool escribir_y_verificar(std::string const& ruta)
{
    std::fstream archivo{ruta,
        std::ios::in | std::ios::out | std::ios::trunc};
    if (!archivo)
    {
        return false;
    }

    archivo << "OK\n";
    if (!archivo)
    {
        return false;
    }

    if (!archivo.seekg(0, std::ios::beg))
    {
        return false;
    }

    std::string linea{};
    if (!std::getline(archivo, linea))
    {
        return false;
    }
    return linea == "OK";
}
}
