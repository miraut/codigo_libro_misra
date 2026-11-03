// CH10-E06. Frontera de tratamiento en el punto de entrada.
#include <cstdint>

namespace ejemplo_frontera
{
struct ErrorProtocolo {};

int ejecutar_aplicacion(); // Implementación del servicio.
void registrar_fallo_final(std::uint32_t codigo) noexcept;
}

int main()
{
    try
    {
        return ejemplo_frontera::ejecutar_aplicacion();
    }
    catch (ejemplo_frontera::ErrorProtocolo const&)
    {
        ejemplo_frontera::registrar_fallo_final(1U);
        return 1;
    }
    catch (...)
    {
        ejemplo_frontera::registrar_fallo_final(2U);
        return 2;
    }
}
