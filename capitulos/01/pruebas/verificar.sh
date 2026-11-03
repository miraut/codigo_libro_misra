#!/bin/sh
set -eu
CDIR=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
TMPDIR_CH01=$(mktemp -d)
trap 'rm -rf "$TMPDIR_CH01"' EXIT HUP INT TERM

printf 'Repositorio: %s\n' "$CDIR"
for cc in g++ clang++; do
    printf '\nCompilador: %s\n' "$cc"
    "$cc" --version | head -n 1
    for file in "$CDIR"/ejemplos/*.cpp; do
        nombre=$(basename "$file")
        case "$nombre" in
            E03_*|E11_*)
                printf '  %s: ejemplo extension, comprobar en paso separado\n' "$nombre"
                ;;
            *)
                "$cc" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors \
                    -c "$file" -o "$TMPDIR_CH01/ejemplo.o" \
                    >"$TMPDIR_CH01/compilacion.log" 2>&1 || {
                    cat "$TMPDIR_CH01/compilacion.log"
                    exit 1
                }
                printf '  %s: compilacion correcta\n' "$nombre"
                ;;
        esac
    done
    for opt in 0 2; do
        "$cc" -std=c++17 -O"$opt" -Wall -Wextra -Wpedantic -pedantic-errors \
            "$CDIR/pruebas/pruebas_capitulo_01.cpp" -o "$TMPDIR_CH01/pruebas"
        "$TMPDIR_CH01/pruebas"
        printf '  pruebas seguras -O%s: correctas\n' "$opt"
    done
    "$cc" -std=c++17 -O1 -g -Wall -Wextra -Wpedantic -pedantic-errors \
        -fsanitize=undefined -fno-sanitize-recover=all \
        "$CDIR/pruebas/pruebas_capitulo_01.cpp" -o "$TMPDIR_CH01/pruebas_ubsan"
    "$TMPDIR_CH01/pruebas_ubsan"
    printf '  UBSan: sin diagnosticos en rutas ejecutadas\n'
done

printf '\nGCC dialecto estricto: rechazo previsto de VLA\n'
for file in "$CDIR"/ejemplos/E03_*.cpp "$CDIR"/ejemplos/E11_*.cpp; do
    if g++ -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c "$file" -o "$TMPDIR_CH01/ext.o" >"$TMPDIR_CH01/error_esperado.log" 2>&1; then
        printf 'ERROR: GCC acepto la extension de %s en modo estricto\n' "$(basename "$file")"
        exit 1
    fi
    grep -q 'variable length array' "$TMPDIR_CH01/error_esperado.log"
    printf '  %s: rechazo esperado por array de longitud variable\n' "$(basename "$file")"
done

printf '\nGCC dialecto permisivo: aceptacion prevista de VLA\n'
for file in "$CDIR"/ejemplos/E03_*.cpp "$CDIR"/ejemplos/E11_*.cpp; do
    g++ -std=gnu++17 -Wall -Wextra -c "$file" -o "$TMPDIR_CH01/ext.o"
    printf '  %s: compilacion correcta con extension\n' "$(basename "$file")"
done
printf '\nVerificacion concluida. No se ha ejecutado ninguna ruta de comportamiento indefinido.\n'
