// CH07-E15a. interfaz: sensor_port.hpp
#ifndef CAP7_SENSOR_PORT_HPP
#define CAP7_SENSOR_PORT_HPP
#include <cstdint>
#include <memory>

namespace adquisicion
{
class SensorPort final
{
public:
    SensorPort();
    ~SensorPort();

    SensorPort(SensorPort const&) = delete;
    SensorPort& operator=(SensorPort const&) = delete;

    std::uint32_t leer() const noexcept;

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};
}
#endif // CAP7_SENSOR_PORT_HPP
