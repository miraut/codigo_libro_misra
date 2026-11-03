// CH12-E15. Componentes con propiedad explícita del estado compartido.
#include <cstdint>
#include <mutex>
#include <optional>

namespace ejemplo_adquisicion_integrada
{
struct Registros
{
    volatile std::uint32_t estado{0U};
    volatile std::uint32_t dato{0U};
};

struct Muestra
{
    std::uint32_t secuencia{0U};
    std::uint32_t valor{0U};
};

class CanalMuestras
{
public:
    bool publicar(Muestra const& muestra)
    {
        std::lock_guard<std::mutex> bloqueo{mutex_};
        if (pendiente_.has_value())
        {
            return false;
        }
        pendiente_ = muestra;
        return true;
    }

    bool retirar(Muestra& muestra)
    {
        std::lock_guard<std::mutex> bloqueo{mutex_};
        if (!pendiente_.has_value())
        {
            return false;
        }
        muestra = *pendiente_;
        pendiente_.reset();
        return true;
    }

private:
    std::mutex mutex_{};
    std::optional<Muestra> pendiente_{};
};

class Adquisidor
{
public:
    Adquisidor(Registros volatile& registros, CanalMuestras& canal)
        : registros_{registros}, canal_{canal}
    {
    }

    bool adquirir(std::uint32_t secuencia)
    {
        std::uint32_t const estado{registros_.estado};
        if ((estado & 1U) == 0U)
        {
            return false;
        }

        std::uint32_t const valor{registros_.dato};
        return canal_.publicar(Muestra{secuencia, valor});
    }

private:
    Registros volatile& registros_;
    CanalMuestras& canal_;
};
}
