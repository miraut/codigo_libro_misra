# Capítulo 5. Estados válidos y expresiones sin sorpresas

[← Índice del repositorio](../../README.md) · [Libro gratuito: lectura en línea y PDF versionado](https://miraut.github.io/libro_MISRA_CPP_2023/)

## El problema que estudiamos

Una medida sin inicializar plantea un problema evidente. Inicializarla con cero elimina la lectura indeterminada, pero puede introducir ambigüedad entre una medida legítima y una adquisición fallida.

Este capítulo del libro explica **inicialización, `const`, precedencia, secuenciación, efectos secundarios persistentes, asignaciones y regiones solapadas.**. Los archivos de esta carpeta permiten seguir el razonamiento con código real: observar la construcción que plantea la dificultad, estudiar una alternativa y comprobar las hipótesis que hacen válida una solución. La explicación del libro proporciona el contexto necesario para interpretar cada fragmento.

## Qué puedes aprender con este código

Sigue `CH05-E01.cpp` a `CH05-E23.cpp`. Los archivos `pruebas/prueba_CH05-E??.cpp` ofrecen un punto de partida para comprobar las rutas seguras y para discutir las diferencias entre sintaxis y significado.

La lectura resulta más útil si, antes de consultar la solución, intentas responder a dos preguntas: **¿qué garantiza C++17 en este punto?** y **¿qué propiedad adicional necesitamos justificar para el sistema?** Las respuestas pueden depender de la plataforma, de las condiciones de entrada o de reglas MISRA que se estudian conjuntamente.

## Archivos disponibles

El material adjunto para este capítulo contiene exactamente estas carpetas:

| Ruta | Para qué sirve |
|---|---|
| [`ejemplos/`](ejemplos/) | Fragmentos C++17 vinculados con las explicaciones del capítulo (23 archivos) |
| [`pruebas/`](pruebas/) | Pruebas y comprobaciones disponibles (23 archivos) |

La organización refleja los archivos disponibles en esta edición del repositorio. No se presupone que todas las carpetas contengan ejecutables autónomos ni que exista un sistema de construcción común a los dieciséis capítulos. Algunos ejemplos están pensados para compilarse a objeto, otros requieren enlazar varios archivos y otros se han incluido para estudiar un defecto sin ejecutarlo.

## Cómo comprobar los ejemplos

Hay una prueba `.cpp` por ejemplo; no hay un script general incluido. Antes de ejecutar una prueba, examina qué funciones invoca y si evita las rutas defectuosas mostradas con fines didácticos.

Para un fragmento **autónomo, identificado previamente como seguro y compilable**, una primera comprobación puede ser:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c ejemplos/ARCHIVO.cpp
```

Sustituye `ARCHIVO.cpp` por un nombre existente en `ejemplos/`. Esta orden solo comprueba la traducción del archivo, no su comportamiento durante la ejecución. Para casos con cabeceras, bibliotecas, opciones de preprocesador o varias unidades de traducción, sigue las instrucciones específicas anteriores y el contexto del capítulo. Comprueba también qué compiladores y herramientas están instalados antes de utilizar scripts.

> **Antes de ejecutar:** Añadir paréntesis no determina por sí solo el orden de evaluación. No ejecutes fragmentos que lean valores indeterminados o copien memoria solapada de forma indebida. Los ejemplos intencionadamente incorrectos pueden servir para examinar un diagnóstico o un rechazo del compilador, pero no deben ejecutarse para provocar comportamiento indefinido. Una compilación correcta, una prueba funcional satisfactoria o la ausencia de advertencias no constituyen por sí solas una declaración de conformidad con MISRA C++:2023.

## Relación con el libro y colaboración

La guía explica el fundamento de cada decisión, las reglas relevantes por identificador y las limitaciones de las alternativas. **[Consulta gratuitamente el capítulo en la web del libro y descarga su edición PDF](https://miraut.github.io/libro_MISRA_CPP_2023/)**. La URL se completará cuando esté disponible la dirección pública definitiva.

Si detectas un error o propones una mejora, acompaña tu observación del archivo afectado, la versión de C++ y las condiciones necesarias para reproducirla. Las contribuciones deben mantener la claridad de los ejemplos y evitar introducir material protegido de la publicación oficial MISRA.

**Licencias:** el código original de los ejemplos se ofrece bajo MIT; el texto editorial original del libro se distribuye bajo CC BY-NC-SA 4.0. Ambas licencias se aplican a materiales diferentes. El estándar MISRA y sus marcas pertenecen a sus titulares; esta obra es independiente y no está avalada por el consorcio.
