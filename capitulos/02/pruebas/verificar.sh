#!/bin/sh
# Comprobaciones locales de traduccion y comportamiento definido. NO son verificacion MISRA.
set -eu
RAIZ=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
LOG="$RAIZ/control/RESULTADOS_COMPILACION_Y_PRUEBAS.txt"
TEMP=$(mktemp -d)
trap 'rm -rf "$TEMP"' EXIT HUP INT TERM
: > "$LOG"
printf '%s\n' 'Capitulo 2: compilacion C++17 y pruebas de rutas seguras' >> "$LOG"
for COMPILADOR in g++ clang++; do
    command -v "$COMPILADOR" >/dev/null 2>&1 || { echo "Falta: $COMPILADOR" >&2; exit 1; }
    "$COMPILADOR" --version | head -n 1 >> "$LOG"
    for ID in 01 02 03 04 05 06 07 08 09 10 11 12; do
        "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
            -c "$RAIZ/ejemplos/CH02-E$ID.cpp" -o "$TEMP/$ID.o" \
            2>> "$LOG"
        printf 'COMPILA %s E%s: OK\n' "$COMPILADOR" "$ID" >> "$LOG"
    done
    "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
        -c "$RAIZ/ejemplos/CH02-E13_solucion.cpp" -o "$TEMP/13.o" \
        2>> "$LOG"
    printf 'COMPILA %s E13: OK\n' "$COMPILADOR" >> "$LOG"
    for ID in 03 04 05 06 07 09 11 13; do
        "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
            -pthread -O0 "$RAIZ/pruebas/test_e$ID.cpp" \
            -o "$TEMP/prueba_$ID" 2>> "$LOG"
        "$TEMP/prueba_$ID"
        printf 'PRUEBA %s E%s: OK\n' "$COMPILADOR" "$ID" >> "$LOG"
    done
    "$COMPILADOR" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
        "$RAIZ/ejemplos/caso_modulos/lectura.cpp" \
        "$RAIZ/ejemplos/caso_modulos/control.cpp" \
        "$RAIZ/ejemplos/caso_modulos/prueba.cpp" \
        -o "$TEMP/caso_modulos" 2>> "$LOG"
    "$TEMP/caso_modulos"
    printf 'MODULOS %s: OK\n' "$COMPILADOR" >> "$LOG"
    for ID in 03 04 05 06 07 09 11 13; do
        "$COMPILADOR" -std=c++17 -O1 -g -pthread \
            -fsanitize=undefined -fno-sanitize-recover=undefined \
            "$RAIZ/pruebas/test_e$ID.cpp" -o "$TEMP/san_$ID" 2>> "$LOG"
        "$TEMP/san_$ID"
        printf 'UBSAN %s E%s: SIN DIAGNOSTICOS\n' "$COMPILADOR" "$ID" >> "$LOG"
    done
done
printf '%s\n' 'IMPORTANTE: E01, E02 y E12 contienen rutas deliberadamente inseguras; solo se compilan.' >> "$LOG"
printf '%s\n' 'No se ha ejecutado una herramienta de comprobacion normativa MISRA.' >> "$LOG"
printf 'Finalizado. Registro: %s\n' "$LOG"
