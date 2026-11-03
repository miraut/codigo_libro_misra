// CH08-E17. Problemático: la lambda devuelta captura this implícitamente.
#include <cstdint>

class ControladorCan
{
public:
    explicit ControladorCan(std::uint32_t canal) noexcept
        : canal_{canal}
    {
    }

    auto crear_consulta() const noexcept
    {
        return [=]() noexcept { return canal_; };
    }

private:
    std::uint32_t canal_;
};
