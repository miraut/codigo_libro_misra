#!/bin/sh
set -eu

BASE=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
MODO=${1:-R1}
if [ "$MODO" != R0 ] && [ "$MODO" != R1 ]; then
    echo "Uso: $0 R0|R1" >&2
    exit 2
fi

TRABAJO=$(mktemp -d)
trap 'rm -rf "$TRABAJO"' EXIT INT TERM
CFLAGS='-std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -Werror -O1 -g'

printf 'Escenario educativo: %s\n' "$MODO"
printf 'Flags: %s\n' "$CFLAGS"
for COMPILADOR in g++ clang++; do
    echo "== Compilador: $COMPILADOR =="
    "$COMPILADOR" --version | head -n 1

    # Compilacion a objeto sin enlazar y sin ejecutar los ejemplos peligrosos.
    for EJEMPLO in E01_contrato_sin_cuerpo.cpp E04_registro_hardware_NO_EJECUTAR.cpp E03_ODR_NO_ENLAZAR_a.cpp E03_ODR_NO_ENLAZAR_b.cpp; do
        "$COMPILADOR" $CFLAGS -I"$BASE/caso_integrador/include" -c \
          "$BASE/ejemplos/$EJEMPLO" -o "$TRABAJO/${EJEMPLO%.cpp}.o"
        echo "SOLO_COMPILADO_NO_EJECUTADO $EJEMPLO"
    done

    for PERFIL in LABORATORIO EQUIPO; do
        if [ "$MODO" = R0 ] && [ "$PERFIL" = EQUIPO ]; then
            echo "OMITIDO_PERFIL_EQUIPO_EN_R0"
            continue
        fi
        LIBS=''
        if [ "$PERFIL" = EQUIPO ]; then
            "$COMPILADOR" $CFLAGS -I"$BASE/caso_integrador/include" -c \
              "$BASE/caso_integrador/proveedor_simulado/proveedor_ficticio.cpp" \
              -o "$TRABAJO/proveedor_ficticio.o"
            ar rcs "$TRABAJO/libproveedor_ficticio.a" "$TRABAJO/proveedor_ficticio.o"
            LIBS="$TRABAJO/libproveedor_ficticio.a"
        fi
        "$COMPILADOR" $CFLAGS -D"CH16_PERFIL_$PERFIL" \
          -I"$BASE/caso_integrador/include" \
          "$BASE/caso_integrador/src/control.cpp" \
          "$BASE/caso_integrador/src/origen_perfil.cpp" \
          "$BASE/caso_integrador/pruebas/pruebas_control.cpp" \
          $LIBS -o "$TRABAJO/pruebas_$PERFIL"
        "$TRABAJO/pruebas_$PERFIL"
        echo "OK_PERFIL $PERFIL 8_ESCENARIOS_FUNCIONALES"
    done

    if [ "$MODO" = R1 ]; then
        # No se permite una configuracion sin perfil o con ambos perfiles.
        if "$COMPILADOR" $CFLAGS -I"$BASE/caso_integrador/include" \
          -c "$BASE/caso_integrador/src/origen_perfil.cpp" \
          -o "$TRABAJO/ninguno.o" >/dev/null 2>&1; then
            echo "ERROR: no rechazo perfil no definido" >&2
            exit 1
        fi
        if "$COMPILADOR" $CFLAGS -DCH16_PERFIL_EQUIPO -DCH16_PERFIL_LABORATORIO \
          -I"$BASE/caso_integrador/include" \
          -c "$BASE/caso_integrador/src/origen_perfil.cpp" \
          -o "$TRABAJO/ambos.o" >/dev/null 2>&1; then
            echo "ERROR: no rechazo perfiles simultaneos" >&2
            exit 1
        fi
        echo 'OK_RECHAZO_CONFIGURACION ambos perfiles y ningun perfil'
    fi
 done

if [ "$MODO" = R1 ]; then
    echo '== UBSan Clang, rutas seguras =='
    for PERFIL in LABORATORIO EQUIPO; do
        LIBS=''
        if [ "$PERFIL" = EQUIPO ]; then
            clang++ $CFLAGS -fsanitize=undefined -fno-sanitize-recover=all \
              -I"$BASE/caso_integrador/include" -c \
              "$BASE/caso_integrador/proveedor_simulado/proveedor_ficticio.cpp" \
              -o "$TRABAJO/proveedor_ubsan.o"
            ar rcs "$TRABAJO/libproveedor_ubsan.a" "$TRABAJO/proveedor_ubsan.o"
            LIBS="$TRABAJO/libproveedor_ubsan.a"
        fi
        clang++ $CFLAGS -fsanitize=undefined -fno-sanitize-recover=all \
          -D"CH16_PERFIL_$PERFIL" -I"$BASE/caso_integrador/include" \
          "$BASE/caso_integrador/src/control.cpp" \
          "$BASE/caso_integrador/src/origen_perfil.cpp" \
          "$BASE/caso_integrador/pruebas/pruebas_control.cpp" \
          $LIBS -o "$TRABAJO/ubsan_$PERFIL"
        UBSAN_OPTIONS=halt_on_error=1 "$TRABAJO/ubsan_$PERFIL"
        echo "OK_UBSAN $PERFIL 8_ESCENARIOS_FUNCIONALES_SIN_DIAGNOSTICOS"
    done
fi

echo "RESULTADO_FINAL $MODO OK"
