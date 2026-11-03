#include "medidas_adquisicion.hpp"
int main()
{
    supervision::Muestra muestra{0U, 10U};
    supervision::registrar(muestra);
    return 0;
}
