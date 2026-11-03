#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
mkdir -p control/resultados
informe=control/RESULTADOS_COMPILACION_Y_PRUEBAS.txt
{
  printf 'Capitulo 6: C++17, comprobaciones con GCC y Clang\n'
  date -u '+Fecha UTC: %Y-%m-%dT%H:%M:%SZ'
  g++ --version | head -n 1
  clang++ --version | head -n 1
  for compilador in g++ clang++; do
    printf '\nCOMPILADOR: %s\n' "$compilador"
    for archivo in ejemplos/E??.cpp; do
      nombre=$(basename "$archivo" .cpp)
      "$compilador" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c "$archivo" -o "control/resultados/${compilador}_${nombre}.o" 2>"control/resultados/${compilador}_${nombre}.log"
      printf 'OK: %s\n' "$archivo"
    done
    "$compilador" -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors pruebas/pruebas_comportamiento.cpp -o "control/resultados/${compilador}_pruebas"
    "control/resultados/${compilador}_pruebas"
    printf 'OK: pruebas funcionales\n'
    "$compilador" -std=c++17 -O1 -g -fsanitize=undefined -fno-sanitize-recover=all pruebas/pruebas_comportamiento.cpp -o "control/resultados/${compilador}_ubsan"
    "control/resultados/${compilador}_ubsan"
    printf 'OK: UBSan sobre rutas de prueba\n'
    for neg in pruebas/no_compila_conversion_implicita.cpp pruebas/no_compila_cast_base_virtual.cpp; do
      if "$compilador" -std=c++17 -pedantic-errors -c "$neg" -o /tmp/cap06_no.o 2>"control/resultados/${compilador}_$(basename "$neg" .cpp).log"; then
        printf 'ERROR: debia rechazarse %s\n' "$neg"
        exit 1
      else
        printf 'RECHAZO ESPERADO: %s\n' "$neg"
      fi
    done
  done
} > "$informe" 2>&1
printf 'Resultados disponibles en %s\n' "$informe"
