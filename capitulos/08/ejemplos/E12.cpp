// CH08-E12. El llamante entrega un valor; el receptor puede moverlo.
#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

class AlmacenLecturas
{
public:
    void reemplazar(std::vector<std::uint32_t> nuevas_lecturas)
    {
        lecturas_ = std::move(nuevas_lecturas);
    }

    std::optional<std::uint32_t> primera() const noexcept
    {
        if (lecturas_.empty())
        {
            return std::nullopt;
        }

        return lecturas_.front();
    }

private:
    std::vector<std::uint32_t> lecturas_{};
};
