// CH01-E10. Precondición comprobable de la plataforma objetivo.
#include <climits>

static_assert(CHAR_BIT == 8, "El protocolo requiere bytes de ocho bits");
