// CH14-E06. El resultado de operator[] puede representar un bit, no una copia.
#include <vector>

namespace diagnostico
{
void marcar_estado()
{
    std::vector<bool> avisos{false, false, false};
    auto acceso_al_bit = avisos[0];
    acceso_al_bit = true;
    bool const primer_aviso = avisos[0];
    (void)primer_aviso;
}
}
