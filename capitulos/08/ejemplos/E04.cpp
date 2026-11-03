// CH08-E04. El adaptador conserva la firma y documenta el dato utilizado.
#include <cstdint>

class Notificador
{
public:
    virtual ~Notificador() = default;
    virtual void comunicar(std::uint32_t codigo,
                           std::uint32_t origen) noexcept = 0;
};

class NotificadorLocal final : public Notificador
{
public:
    void comunicar(std::uint32_t codigo,
                   std::uint32_t) noexcept override
    {
        ultimo_codigo_ = codigo;
    }

    std::uint32_t ultimo_codigo() const noexcept
    {
        return ultimo_codigo_;
    }

private:
    std::uint32_t ultimo_codigo_{0U};
};
