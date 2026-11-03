// CH12-E07. Una posición compartida con exclusión mutua.
#include <cstdint>
#include <mutex>
#include <optional>

namespace ejemplo_bandeja
{
struct Muestra
{
    std::uint32_t secuencia{0U};
    std::uint32_t valor{0U};
};

class BandejaMuestras
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
}
