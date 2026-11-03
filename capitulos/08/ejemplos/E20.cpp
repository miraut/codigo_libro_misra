// CH08-E20. Cola de tramas de capacidad fija y contrato de resultados.
#include <array>
#include <cstddef>
#include <cstdint>

enum class EstadoTransmision : std::uint8_t
{
    sin_trabajo,
    transmitida,
    rechazada
};

struct TramaCan
{
    std::uint32_t identificador;
    std::array<std::uint8_t, 8U> datos;
};

class ColaRetransmision
{
public:
    bool insertar(TramaCan const& trama) noexcept
    {
        if (cantidad_ == pendientes_.size())
        {
            return false;
        }

        pendientes_[final_] = trama;
        final_ = (final_ + 1U) % pendientes_.size();
        ++cantidad_;
        return true;
    }

    bool extraer(TramaCan& trama) noexcept
    {
        if (cantidad_ == 0U)
        {
            return false;
        }

        trama = pendientes_[inicio_];
        inicio_ = (inicio_ + 1U) % pendientes_.size();
        --cantidad_;
        return true;
    }

    std::size_t cantidad() const noexcept
    {
        return cantidad_;
    }

private:
    std::array<TramaCan, 4U> pendientes_{};
    std::size_t inicio_{0U};
    std::size_t final_{0U};
    std::size_t cantidad_{0U};
};

class SalidaCanSimulada
{
public:
    bool transmitir(TramaCan const& trama) noexcept
    {
        if (trama.identificador > 2047U)
        {
            return false;
        }

        ultima_trama_ = trama;
        return true;
    }

    std::uint32_t ultimo_identificador() const noexcept
    {
        return ultima_trama_.identificador;
    }

private:
    TramaCan ultima_trama_{};
};

EstadoTransmision atender_siguiente(ColaRetransmision& cola,
                                    SalidaCanSimulada& salida) noexcept
{
    TramaCan trama{};

    if (!cola.extraer(trama))
    {
        return EstadoTransmision::sin_trabajo;
    }

    if (!salida.transmitir(trama))
    {
        return EstadoTransmision::rechazada;
    }

    return EstadoTransmision::transmitida;
}
