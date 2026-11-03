# Capítulo 3. El módulo comienza antes de que el compilador vea una función

[← Índice del repositorio](../../README.md) · [Libro gratuito: lectura en línea y PDF versionado](URL_WEB_DEL_LIBRO_PENDIENTE)

## El problema que estudiamos

Dos archivos pueden compilar por separado y entrar en conflicto al integrarse. Algunas infracciones de la regla de definición única ni siquiera necesitan producir un error del enlazador.

Este capítulo del libro explica **léxico, identificadores, ámbitos, cabeceras, enlace y regla de definición única (ODR).**. Los archivos de esta carpeta permiten seguir el razonamiento con código real: observar la construcción que plantea la dificultad, estudiar una alternativa y comprobar las hipótesis que hacen válida una solución. La explicación del libro proporciona el contexto necesario para interpretar cada fragmento.

## Qué puedes aprender con este código

Recorre `ejemplos/E01.cpp` a `E26.cpp` con el texto del capítulo. Después compara `integracion_segura/` con los proyectos de `problemas/`: `odr_enlace/` y `odr_silenciosa/` ilustran dificultades distintas. `taller_solucion/` permite estudiar una organización alternativa.

La lectura resulta más útil si, antes de consultar la solución, intentas responder a dos preguntas: **¿qué garantiza C++17 en este punto?** y **¿qué propiedad adicional necesitamos justificar para el sistema?** Las respuestas pueden depender de la plataforma, de las condiciones de entrada o de reglas MISRA que se estudian conjuntamente.

## Archivos disponibles

El material adjunto para este capítulo contiene exactamente estas carpetas:

| Ruta | Para qué sirve |
|---|---|
| [`ejemplos/`](ejemplos/) | Fragmentos C++17 vinculados con las explicaciones del capítulo (26 archivos) |
| [`integracion_segura/`](integracion_segura/) | Proyecto de integración propuesto para contrastar las alternativas (4 archivos) |
| [`problemas/`](problemas/) | Proyectos deliberadamente problemáticos para analizar (20 archivos) |
| [`taller_solucion/`](taller_solucion/) | Resolución del taller final (5 archivos) |
| [`tests/`](tests/) | Comprobaciones del capítulo, con esta denominación específica (2 archivos) |

Los casos de `problemas/` están separados en `alias_inconsistente/`, `cabecera_anonima/`, `inline_buscado_distinto/`, `odr_enlace/`, `odr_silenciosa/`. Cada carpeta debe estudiarse como un proyecto propio, con sus unidades de traducción.

La organización refleja los archivos disponibles en esta edición del repositorio. No se presupone que todas las carpetas contengan ejecutables autónomos ni que exista un sistema de construcción común a los dieciséis capítulos. Algunos ejemplos están pensados para compilarse a objeto, otros requieren enlazar varios archivos y otros se han incluido para estudiar un defecto sin ejecutarlo.

## Cómo comprobar los ejemplos

La carpeta de comprobaciones se llama `tests/`, no `pruebas/`. La integración segura requiere compilar conjuntamente sus archivos `.cpp`. Para los proyectos problemáticos, razona sobre declaraciones y definiciones sin depender de su ejecución.

Para un fragmento **autónomo, identificado previamente como seguro y compilable**, una primera comprobación puede ser:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c ejemplos/ARCHIVO.cpp
```

Sustituye `ARCHIVO.cpp` por un nombre existente en `ejemplos/`. Esta orden solo comprueba la traducción del archivo, no su comportamiento durante la ejecución. Para casos con cabeceras, bibliotecas, opciones de preprocesador o varias unidades de traducción, sigue las instrucciones específicas anteriores y el contexto del capítulo. Comprueba también qué compiladores y herramientas están instalados antes de utilizar scripts.

> **Antes de ejecutar:** No ejecutes `problemas/odr_silenciosa/` ni `problemas/inline_buscado_distinto/` como si fueran demostraciones funcionales válidas: su propósito es estudiar riesgos de integración. Los ejemplos intencionadamente incorrectos pueden servir para examinar un diagnóstico o un rechazo del compilador, pero no deben ejecutarse para provocar comportamiento indefinido. Una compilación correcta, una prueba funcional satisfactoria o la ausencia de advertencias no constituyen por sí solas una declaración de conformidad con MISRA C++:2023.

## Relación con el libro y colaboración

La guía explica el fundamento de cada decisión, las reglas relevantes por identificador y las limitaciones de las alternativas. **[Consulta gratuitamente el capítulo en la web del libro y descarga su edición PDF](URL_WEB_DEL_LIBRO_PENDIENTE)**. La URL se completará cuando esté disponible la dirección pública definitiva.

Si detectas un error o propones una mejora, acompaña tu observación del archivo afectado, la versión de C++ y las condiciones necesarias para reproducirla. Las contribuciones deben mantener la claridad de los ejemplos y evitar introducir material protegido de la publicación oficial MISRA.

**Licencias:** el código original de los ejemplos se ofrece bajo MIT; el texto editorial original del libro se distribuye bajo CC BY-NC-SA 4.0. Ambas licencias se aplican a materiales diferentes. El estándar MISRA y sus marcas pertenecen a sus titulares; esta obra es independiente y no está avalada por el consorcio.
