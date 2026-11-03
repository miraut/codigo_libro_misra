#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E05.cpp"
int main()
{
    std::uint32_t numero=14U; assert(condiciones::existe(&numero)); assert(!condiciones::existe(nullptr)); assert(condiciones::existe_de_forma_explicita(&numero));
    return 0;
}
