// CH10-E04. La captura por valor pierde la información del tipo derivado.
#include <cstdint>

namespace ejemplo_captura
{
struct ErrorDispositivo
{
    virtual ~ErrorDispositivo() noexcept = default;
    virtual std::uint32_t codigo() const noexcept { return 1U; }
};

struct ErrorTemperatura : ErrorDispositivo
{
    std::uint32_t codigo() const noexcept override { return 27U; }
};

std::uint32_t capturar_por_valor()
{
    try
    {
        throw ErrorTemperatura{};
    }
    catch (ErrorDispositivo error) // Problemático: captura por valor.
    {
        return error.codigo(); // Devuelve 1, tras el slicing.
    }
}

std::uint32_t capturar_por_referencia()
{
    try
    {
        throw ErrorTemperatura{};
    }
    catch (ErrorDispositivo const& error)
    {
        return error.codigo(); // Devuelve 27.
    }
}
}
