// CH08-E18. La consulta diferida conserva un valor independiente.
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
        return [canal = canal_]() noexcept { return canal; };
    }

private:
    std::uint32_t canal_;
};
