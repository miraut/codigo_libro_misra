// CH08-E06. Función que abandona la ejecución mediante una excepción.
#include <cstdint>

struct FalloCritico
{
    std::uint32_t codigo;
};

[[noreturn]] void informar_fallo_irrecuperable(std::uint32_t codigo)
{
    throw FalloCritico{codigo};
}
