// CH03-E17. Esquema conceptual: el mismo texto puede resolver otro nombre.
// transformacion.hpp
// namespace supervision
// {
// inline std::uint32_t aplicar(std::uint32_t lectura) noexcept
// {
//     return obtener_escala(lectura);
// }
// }

// adquisicion.cpp, ANTES de incluir transformacion.hpp:
// namespace supervision
// {
// std::uint32_t obtener_escala(std::uint32_t) noexcept;
// }

// diagnostico.cpp, ANTES de incluir transformacion.hpp:
// namespace supervision
// {
// std::uint32_t obtener_escala(double) noexcept;
// }
