# Capítulo 16. Demostrar conformidad cuando importa la auditoría

[← Índice del repositorio](../../README.md) · [Libro gratuito: lectura en línea y PDF versionado](URL_WEB_DEL_LIBRO_PENDIENTE)

## El problema que estudiamos

Un equipo dispone de resultados satisfactorios, pero el expediente no permite demostrar que la variante de equipo y una biblioteca externa hayan quedado dentro del alcance de las verificaciones.

Este capítulo del libro explica **gRP, GEP, GCS, desviaciones, código de terceros, trazabilidad y límites de una declaración de conformidad.**. Los archivos de esta carpeta permiten seguir el razonamiento con código real: observar la construcción que plantea la dificultad, estudiar una alternativa y comprobar las hipótesis que hacen válida una solución. La explicación del libro proporciona el contexto necesario para interpretar cada fragmento.

## Qué puedes aprender con este código

Lee `caso_integrador/CONTRATO.md` antes de estudiar `include/`, `src/` y `proveedor_simulado/`. El archivo `E04_registro_hardware_NO_EJECUTAR.cpp` y los dos `E03_ODR_NO_ENLAZAR_*.cpp` son material de análisis, no pruebas funcionales.

La lectura resulta más útil si, antes de consultar la solución, intentas responder a dos preguntas: **¿qué garantiza C++17 en este punto?** y **¿qué propiedad adicional necesitamos justificar para el sistema?** Las respuestas pueden depender de la plataforma, de las condiciones de entrada o de reglas MISRA que se estudian conjuntamente.

## Archivos disponibles

El material adjunto para este capítulo contiene exactamente estas carpetas:

| Ruta | Para qué sirve |
|---|---|
| [`caso_integrador/`](caso_integrador/) | Proyecto o cabeceras del caso de estudio completo (7 archivos) |
| [`ejemplos/`](ejemplos/) | Fragmentos C++17 vinculados con las explicaciones del capítulo (4 archivos) |
| [`pruebas/`](pruebas/) | Pruebas y comprobaciones disponibles (1 archivos) |

La organización refleja los archivos disponibles en esta edición del repositorio. No se presupone que todas las carpetas contengan ejecutables autónomos ni que exista un sistema de construcción común a los dieciséis capítulos. Algunos ejemplos están pensados para compilarse a objeto, otros requieren enlazar varios archivos y otros se han incluido para estudiar un defecto sin ejecutarlo.

## Cómo comprobar los ejemplos

`pruebas/verificar.sh` admite `R0` y `R1`: desde `capitulos/16/` ejecuta `sh pruebas/verificar.sh R0` y, después, `sh pruebas/verificar.sh R1` si dispones de GCC, Clang y `ar`. R0 omite la variante EQUIPO; R1 incorpora una biblioteca ficticia simulada.

Para un fragmento **autónomo, identificado previamente como seguro y compilable**, una primera comprobación puede ser:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c ejemplos/ARCHIVO.cpp
```

Sustituye `ARCHIVO.cpp` por un nombre existente en `ejemplos/`. Esta orden solo comprueba la traducción del archivo, no su comportamiento durante la ejecución. Para casos con cabeceras, bibliotecas, opciones de preprocesador o varias unidades de traducción, sigue las instrucciones específicas anteriores y el contexto del capítulo. Comprueba también qué compiladores y herramientas están instalados antes de utilizar scripts.

> **Antes de ejecutar:** El proveedor es ficticio y las evidencias son educativas. Ni R1 ni las pruebas de integración demuestran conformidad MISRA del sistema. Los ejemplos intencionadamente incorrectos pueden servir para examinar un diagnóstico o un rechazo del compilador, pero no deben ejecutarse para provocar comportamiento indefinido. Una compilación correcta, una prueba funcional satisfactoria o la ausencia de advertencias no constituyen por sí solas una declaración de conformidad con MISRA C++:2023.

## Relación con el libro y colaboración

La guía explica el fundamento de cada decisión, las reglas relevantes por identificador y las limitaciones de las alternativas. **[Consulta gratuitamente el capítulo en la web del libro y descarga su edición PDF](URL_WEB_DEL_LIBRO_PENDIENTE)**. La URL se completará cuando esté disponible la dirección pública definitiva.

Si detectas un error o propones una mejora, acompaña tu observación del archivo afectado, la versión de C++ y las condiciones necesarias para reproducirla. Las contribuciones deben mantener la claridad de los ejemplos y evitar introducir material protegido de la publicación oficial MISRA.

**Licencias:** el código original de los ejemplos se ofrece bajo MIT; el texto editorial original del libro se distribuye bajo CC BY-NC-SA 4.0. Ambas licencias se aplican a materiales diferentes. El estándar MISRA y sus marcas pertenecen a sus titulares; esta obra es independiente y no está avalada por el consorcio.
