#!/bin/sh
set -eu
RAIZ=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CARPETA="${1:-${RAIZ}/verificaciones_locales}"
mkdir -p "$CARPETA"
: > "$CARPETA/resultado.txt"
for COMPILADOR in g++ clang++; do
    if ! command -v "$COMPILADOR" >/dev/null 2>&1; then
        printf '%s: no disponible\n' "$COMPILADOR" >> "$CARPETA/resultado.txt"
        continue
    fi
    "$COMPILADOR" --version | head -n 1 >> "$CARPETA/resultado.txt"
    for EJEMPLO in "$RAIZ"/ejemplos/*.cpp; do
        ARCHIVO=$(basename "$EJEMPLO" .cpp)
        if [ "$ARCHIVO" = E02_contrato_externo ]; then
            "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
                -I "$RAIZ/caso_integrador/include" -c "$EJEMPLO" \
                -o "$CARPETA/${ARCHIVO}_${COMPILADOR}.o"
        else
            "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
                -c "$EJEMPLO" -o "$CARPETA/${ARCHIVO}_${COMPILADOR}.o"
        fi
        printf '%s %s : compila\n' "$COMPILADOR" "$ARCHIVO" >> "$CARPETA/resultado.txt"
    done
    for VARIANTE in LABORATORIO EQUIPO; do
        cmake -S "$RAIZ/caso_integrador" -B "$CARPETA/${COMPILADOR}_${VARIANTE}" \
            -G Ninja -DCMAKE_CXX_COMPILER="$COMPILADOR" \
            -DCH15_VARIANTE="$VARIANTE" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
            > "$CARPETA/cmake_${COMPILADOR}_${VARIANTE}.txt" 2>&1
        cmake --build "$CARPETA/${COMPILADOR}_${VARIANTE}" \
            >> "$CARPETA/cmake_${COMPILADOR}_${VARIANTE}.txt" 2>&1
        ctest --test-dir "$CARPETA/${COMPILADOR}_${VARIANTE}" --output-on-failure \
            > "$CARPETA/ctest_${COMPILADOR}_${VARIANTE}.txt" 2>&1
        printf '%s %s : pruebas correctas\n' "$COMPILADOR" "$VARIANTE" \
            >> "$CARPETA/resultado.txt"
    done
done
