// CH14-E19. Implementación problemática: salto que omite un destructor.
#include <csetjmp>
#include <string>

namespace recepcion
{
void abandonar_operacion()
{
    std::jmp_buf punto_retorno{};
    if (setjmp(punto_retorno) == 0)
    {
        std::string diagnostico{"operacion iniciada"};
        std::longjmp(punto_retorno, 1);
    }
}
}
