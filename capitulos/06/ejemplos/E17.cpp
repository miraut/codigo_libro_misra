// CH06-E17. Comparacion de punteros a funciones miembro virtuales.
namespace metodos_comparables {
class Unidad {
public:
    virtual ~Unidad() = default;
    virtual void iniciar() noexcept {}
    void detener() noexcept {}
};

using Operacion = void (Unidad::*)() noexcept;

bool hay_operacion(Operacion operacion) noexcept {
    return operacion != nullptr; // Comparacion con nullptr.
}

bool comparar_metodos(Operacion operacion) noexcept {
    return operacion == &Unidad::detener; // Potencialmente virtual: revisar.
}
} // namespace metodos_comparables
