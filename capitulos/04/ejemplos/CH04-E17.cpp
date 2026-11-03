// CH04-E17. Casos didácticos: el compilador acepta más de lo que permite MISRA.
#include <cstdint>

namespace campos
{
struct RegistroConRiesgos
{
    char letra : 3;          // Rule 12.2.2: tipo de carácter inadecuado.
    signed int signo : 1;   // Rule 12.2.3: campo con signo de un bit y con nombre.
    bool valido : 1;        // Tipo aceptado por Rule 12.2.2.
};

struct RegistroDePrueba
{
    std::uint32_t codigo : 3;
    bool alarma : 1;
};
}
