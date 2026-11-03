#include <cassert>
#include <cmath>
#include <limits>
#include "../ejemplos/CH04-E06.cpp"
int main()
{
    assert(caracteres::es_separador(';')); assert(!caracteres::es_separador(',')); assert(caracteres::precede('0','1')); assert(caracteres::codigo_de('A')==std::char_traits<char>::to_int_type('A'));
    return 0;
}
