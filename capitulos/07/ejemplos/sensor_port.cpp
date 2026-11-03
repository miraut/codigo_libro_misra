// CH07-E15b. implementación: sensor_port.cpp
#include "sensor_port.hpp"

namespace adquisicion
{
struct SensorPort::Impl
{
    std::uint32_t ultima_lectura{0U};
};

SensorPort::SensorPort()
    : impl_{std::make_unique<Impl>()}
{
}

SensorPort::~SensorPort() = default;

std::uint32_t SensorPort::leer() const noexcept
{
    return impl_->ultima_lectura;
}
}
