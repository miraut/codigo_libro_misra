// CH06-E15. El despacho virtual en el constructor observa la clase base.
#include <cstdint>

namespace construccion_virtual {
class BaseCanal {
public:
    BaseCanal() noexcept : codigo_registrado_{identificar()} {}
    virtual ~BaseCanal() = default;
    BaseCanal(BaseCanal const&) = delete;
    BaseCanal& operator=(BaseCanal const&) = delete;
    BaseCanal(BaseCanal&&) = delete;
    BaseCanal& operator=(BaseCanal&&) = delete;

    virtual std::uint16_t identificar() const noexcept { return 1U; }
    std::uint16_t codigo_registrado() const noexcept { return codigo_registrado_; }

private:
    std::uint16_t codigo_registrado_{0U};
};

class CanalEspecial final : public BaseCanal {
public:
    std::uint16_t identificar() const noexcept override { return 7U; }
};
} // namespace construccion_virtual
