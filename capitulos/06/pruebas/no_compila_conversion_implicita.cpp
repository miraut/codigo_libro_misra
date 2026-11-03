// Se espera rechazo: constructor explicit no admite paso implicito de entero.
#include "../ejemplos/E09.cpp"
int main() {
    return conversiones_clase::admite_periodo(20U) ? 0 : 1;
}
