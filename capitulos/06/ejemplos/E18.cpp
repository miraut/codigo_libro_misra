// CH06-E18. Recuperacion dinamica desde una base virtual polimorfica.
namespace conversion_virtual {
class InterfazCanal {
public:
    virtual ~InterfazCanal() = default;
    InterfazCanal(InterfazCanal const&) = delete;
    InterfazCanal& operator=(InterfazCanal const&) = delete;
    InterfazCanal(InterfazCanal&&) = delete;
    InterfazCanal& operator=(InterfazCanal&&) = delete;
protected:
    InterfazCanal() = default;
};

class CanalLocal final : public virtual InterfazCanal {};
class CanalRemoto final : public virtual InterfazCanal {};

bool es_local(InterfazCanal* canal) noexcept {
    return dynamic_cast<CanalLocal*>(canal) != nullptr;
}
} // namespace conversion_virtual
