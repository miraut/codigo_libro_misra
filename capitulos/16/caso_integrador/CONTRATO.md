# Contrato didactico del puerto de adquisicion (CH16)

- El productor entrega un numero entero sin signo de 32 bits en `valor` y un indicador booleano de disponibilidad.
- Si el productor devuelve `false`, el valor de `valor` no tiene significado y no debe usarse.
- La aplicacion interpreta como muestras validas los enteros [0, 4095].
- El parametro `umbral` debe pertenecer a [1, 4095]. Un valor fuera de rango se rechaza ANTES de invocar el puerto.
- El estado `normal` se produce cuando la muestra es menor que el umbral, `alarma` si es mayor o igual.
- La conversion de 32 a 16 bits ocurre unicamente despues de verificar <= 4095.
- `FuenteFalsa` y `proveedor_ficticio.cpp` son solo ejemplos para ensayos. Ningun elemento prueba el comportamiento de un producto comercial real.
- C++17 no garantiza por si solo plazos maximos de respuesta, capacidad de tiempo real, ausencia de asignaciones en todas las bibliotecas o seguridad del hardware.
