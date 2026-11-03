#!/bin/sh
set -eu
BASE=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
SALIDA="${1:-${BASE}/verificaciones_de_variantes}"
mkdir -p "$SALIDA"
for COMPILADOR in g++ clang++; do
    for VARIANTE in LABORATORIO EQUIPO; do
        "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
            -D"CH15_VARIANTE_${VARIANTE}=1" \
            -c "$BASE/ejemplos/E01_variante_oculta.cpp" \
            -o "$SALIDA/${COMPILADOR}_${VARIANTE}.o"
        "$COMPILADOR" -std=c++17 -D"CH15_VARIANTE_${VARIANTE}=1" \
            -E "$BASE/ejemplos/E01_variante_oculta.cpp" \
            > "$SALIDA/${COMPILADOR}_${VARIANTE}.ii"
        printf 'Compilado %s con CH15_VARIANTE_%s\n' "$COMPILADOR" "$VARIANTE"
    done
done
# Los fallos previstos se distinguen de las pruebas que deben finalizar correctamente.
if cmake -S "$BASE/caso_integrador" -B "$SALIDA/sin_variante" \
    -G Ninja > "$SALIDA/sin_variante.log" 2>&1; then
    printf 'ERROR: CMake acepto un proyecto sin variante\n' >&2
    exit 1
fi
if cmake -S "$BASE/caso_integrador" -B "$SALIDA/variante_invalida" \
    -G Ninja -DCH15_VARIANTE=DESCONOCIDA \
    > "$SALIDA/variante_invalida.log" 2>&1; then
    printf 'ERROR: CMake acepto una variante desconocida\n' >&2
    exit 1
fi
printf 'Comprobaciones negativas: CMake rechazo ambas configuraciones invalidas\n'
