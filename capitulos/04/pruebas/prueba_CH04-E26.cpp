#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E26.cpp"
int main()
{
    auto limites=temperatura::Limites{75.0,0.2}; assert(temperatura::evaluar(74.0,limites).value()==temperatura::Dictamen::normal); assert(temperatura::evaluar(75.0,limites).value()==temperatura::Dictamen::indeterminado); assert(temperatura::evaluar(75.3,limites).value()==temperatura::Dictamen::alarma); assert(!temperatura::evaluar(std::numeric_limits<double>::quiet_NaN(),limites).has_value()); assert(!temperatura::evaluar(80.0,temperatura::Limites{75.0,-1.0}).has_value());
    return 0;
}
