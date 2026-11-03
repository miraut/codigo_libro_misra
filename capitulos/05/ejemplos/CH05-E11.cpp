// CH05-E11. Un cambio de estado persistente oculto tras un &&.
#include <cstdint>

namespace efectos_persistentes {
class RegistroAvisos {
public:
    bool anotar_y_comprobar_limite() noexcept
    {
        ++avisos_;
        return avisos_ >= 3U;
    }

    std::uint32_t cantidad() const noexcept { return avisos_; }

private:
    std::uint32_t avisos_{0U};
};

bool comprobar_en_condicion(bool muestra_valida,
                           RegistroAvisos& registro) noexcept
{
    return muestra_valida && registro.anotar_y_comprobar_limite();
}

bool comprobar_con_fases(bool muestra_valida,
                        RegistroAvisos& registro) noexcept
{
    if (!muestra_valida)
    {
        return false;
    }

    bool const limite_alcanzado = registro.anotar_y_comprobar_limite();
    return limite_alcanzado;
}
} // namespace efectos_persistentes
