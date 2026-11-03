// CH06-E19. Consultar el tipo dinamico frente a expresar comportamiento virtual.
#include <cstdint>
#include <typeinfo>

namespace identificacion_dinamica {
enum class ClaseCanal : std::uint8_t { local, remoto };

class Canal {
public:
    virtual ~Canal() = default;
    Canal(Canal const&) = delete;
    Canal& operator=(Canal const&) = delete;
    Canal(Canal&&) = delete;
    Canal& operator=(Canal&&) = delete;
protected:
    Canal() = default;
public:
    virtual ClaseCanal clase() const noexcept = 0;
};

class CanalRemoto final : public Canal {
public:
    ClaseCanal clase() const noexcept override { return ClaseCanal::remoto; }
};

bool consulta_por_rtti(Canal const& canal) {
    return typeid(canal) == typeid(CanalRemoto); // Rule 8.2.9.
}

bool consulta_por_interfaz(Canal const& canal) noexcept {
    return canal.clase() == ClaseCanal::remoto;
}
} // namespace identificacion_dinamica
