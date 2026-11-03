// CH06-E04. Un guardia de uso exclusivo no permite copia ni movimiento.
namespace gestion_ambito {
class RegistroExclusividad {
public:
    bool ocupado() const noexcept { return ocupado_; }
    void ocupar() noexcept { ocupado_ = true; }
    void liberar() noexcept { ocupado_ = false; }
private:
    bool ocupado_{false};
};

class GuardiaExclusiva {
public:
    explicit GuardiaExclusiva(RegistroExclusividad& recurso) noexcept
        : recurso_{recurso} { recurso_.ocupar(); }

    ~GuardiaExclusiva() noexcept { recurso_.liberar(); }
    GuardiaExclusiva(GuardiaExclusiva const&) = delete;
    GuardiaExclusiva& operator=(GuardiaExclusiva const&) = delete;
    GuardiaExclusiva(GuardiaExclusiva&&) = delete;
    GuardiaExclusiva& operator=(GuardiaExclusiva&&) = delete;

private:
    RegistroExclusividad& recurso_;
};
} // namespace gestion_ambito
