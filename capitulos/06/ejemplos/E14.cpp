// CH06-E14. El grafo de herencia contiene dos subobjetos de la misma base.
namespace herencia_mixta {
struct IdentidadDispositivo {
    unsigned revision{1U};
};
struct RutaVirtual : virtual IdentidadDispositivo {};
struct RutaDirecta : IdentidadDispositivo {};
struct UnidadHibrida : RutaVirtual, RutaDirecta {};

// Es posible construir UnidadHibrida, pero contiene dos IdentidadDispositivo.
// La ambiguedad se haria patente al solicitar revision sin especificar ruta.
} // namespace herencia_mixta
