// Se espera rechazo: static_cast desde la base virtual al tipo derivado.
#include "../ejemplos/E18.cpp"
int main() {
    conversion_virtual::CanalLocal local{};
    conversion_virtual::InterfazCanal* base = &local;
    auto* derivada = static_cast<conversion_virtual::CanalLocal*>(base);
    return derivada == nullptr ? 1 : 0;
}
