# Guía de supervivencia no oficial para MISRA C++:2023

### Código de ejemplo en C++17, ejercicios y comprobaciones

Este repositorio acompaña el libro **_Guía de supervivencia no oficial para MISRA C++:2023_**, una obra independiente y gratuita en español sobre el desarrollo de software C++17 en sistemas críticos. Aquí encontrarás ejemplos para examinar comportamientos del lenguaje, contrastar alternativas de diseño y comprender mejor las decisiones que hay detrás de las recomendaciones de MISRA.

El código se ha escrito para **aprender a razonar sobre situaciones reales de ingeniería**. Hay fragmentos que muestran una solución, otros que exponen un defecto intencionado y pequeños proyectos que solo se comprenden al estudiar varias unidades de traducción o configuraciones de compilación. Su propósito es acompañar la explicación, no sustituirla.

> **📖 Libro gratuito:** [leer la obra en la web y descargar versiones identificadas en PDF](https://miraut.github.io/libro_MISRA_CPP_2023/). La dirección canónica se incorporará cuando se publique el sitio. Todas las versiones y formatos del libro son de acceso gratuito.

## Empieza por aquí

Si acabas de descubrir el proyecto, te recomendamos comenzar por el **[capítulo 1](capitulos/01/README.md)**, que muestra por qué un programa que compila y supera pruebas puede seguir planteando problemas de comportamiento. Si ya trabajas con C++17, puedes ir directamente al tema que necesites: conversiones, vida de objetos, excepciones, concurrencia o análisis estático.

En cada carpeta de código de los capítulos encontrarás un `README.md` que explica el problema tratado, el material disponible y las consideraciones previas para estudiarlo. El libro en cada capítulo presenta primero una situación de programación concreta y desarrolla después las propiedades del lenguaje y las reglas MISRA relacionadas. Resulta útil **leer el caso, anticipar qué debería ocurrir y contrastarlo con el código** antes de consultar la alternativa propuesta.

## Índice de código de los capítulos y contenido en relación con el libro

La organización **no es idéntica en todos los capítulos**. Algunos tienen pruebas independientes, otros proyectos de integración y otros solo fragmentos C++17 para estudiar.

| Cap. | Tema | Carpetas incluidas en el material recibido |
|:---:|---|---|
| [01](capitulos/01/README.md) | Qué significa confiar en un programa C++ | `ejemplos/`, `pruebas/` |
| [02](capitulos/02/README.md) | Leer MISRA: de las reglas a las decisiones de ingeniería | `ejemplos/`, `pruebas/` |
| [03](capitulos/03/README.md) | El módulo comienza antes de que el compilador vea una función | `ejemplos/`, `integracion_segura/`, `problemas/`, `taller_solucion/`, `tests/` |
| [04](capitulos/04/README.md) | Los tipos como instrumento de prueba | `ejemplos/`, `pruebas/` |
| [05](capitulos/05/README.md) | Estados válidos y expresiones sin sorpresas | `ejemplos/`, `pruebas/` |
| [06](capitulos/06/README.md) | Diseño de clases: invariantes, propiedad y polimorfismo | `ejemplos/`, `pruebas/` |
| [07](capitulos/07/README.md) | Punteros, referencias, tiempos de vida y memoria | `ejemplos/` |
| [08](capitulos/08/README.md) | Funciones, movimiento y expresiones lambda: contratos y tiempos de vida | `ejemplos/` |
| [09](capitulos/09/README.md) | Plantillas y sobrecarga de operadores: cómo se determina el significado de una expresión | `ejemplos/` |
| [10](capitulos/10/README.md) | Gestión de errores y excepciones: del fallo local a la respuesta del sistema | `ejemplos/` |
| [11](capitulos/11/README.md) | Control de flujo: decisiones, bucles y caminos de salida | `ejemplos/` |
| [12](capitulos/12/README.md) | Estado compartido y concurrencia: orden, visibilidad y reentrancia | `ejemplos/`, `pruebas/` |
| [13](capitulos/13/README.md) | El preprocesador: configuración del producto y significado del código | `caso_integrador/`, `ejemplos/`, `pruebas/` |
| [14](capitulos/14/README.md) | Biblioteca estándar y legado C: contratos que deben hacerse explícitos | `caso_integrador/`, `ejemplos/`, `pruebas/` |
| [15](capitulos/15/README.md) | Análisis estático: del código examinado a la evidencia verificable | `caso_integrador/`, `ejemplos/`, `pruebas/` |
| [16](capitulos/16/README.md) | Demostrar conformidad cuando importa la auditoría | `caso_integrador/`, `ejemplos/`, `pruebas/` |

En particular, el capítulo 3 distingue `problemas/`, `integracion_segura/`, `taller_solucion/` y `tests/`, mientras que los capítulos 13 a 16 incluyen casos de integración con estructura propia. Además, en los capítulos 7 a 11 no hay una carpeta `pruebas/` en la versión recibida. No se trata de un error, simplemente cada capítulo puede tener una estructura de código de ejemplo ligeramente diferente como se muestra a continuación.

## Cómo está organizado el trabajo

```text
README.md
capitulos/
  01/
    README.md
    ejemplos/
    pruebas/
  ...
  03/
    README.md
    ejemplos/
    problemas/
    integracion_segura/
    taller_solucion/
    tests/
  ...
  15/
    README.md
    ejemplos/
    caso_integrador/
      CMakeLists.txt
      include/
      src/
      pruebas/
    pruebas/
  16/
    README.md
    ejemplos/
    caso_integrador/
      CONTRATO.md
      include/
      src/
      proveedor_simulado/
      pruebas/
    pruebas/
```

Este esquema muestra algunas diferencias representativas; la tabla anterior y los README de cada capítulo describen el conjunto completo. Los nombres `E01.cpp`, `CH04-E01.cpp` o `E01_periodo_cero_riesgo.cpp` corresponden a convenciones utilizadas en capítulos distintos. **No hay un identificador de archivo uniforme para toda la obra**.

## Compilar, comprobar y entender

El código se ha orientado a **C++17**. Cuando un archivo es autónomo y está destinado a compilarse por separado, puedes comenzar con:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -pedantic-errors -c capitulos/04/ejemplos/CH04-E01.cpp
```

La opción `-c` permite traducir el archivo sin exigir que contenga `main`. Para proyectos con varios archivos hay que considerar también las cabeceras, las opciones de compilación y el enlace. Los capítulos 1, 2, 6, 15 y 16 incluyen scripts `verificar.sh`; **revísalos antes de ejecutarlos** porque algunos escriben informes en directorios que tendrás que preparar y otros requieren GCC, Clang, CMake o Ninja.

Por ejemplo, el capítulo 15 permite construir dos variantes diferenciadas:

```sh
cmake -S capitulos/15/caso_integrador -B /tmp/misra_ch15_lab -DCH15_VARIANTE=LABORATORIO
cmake --build /tmp/misra_ch15_lab
ctest --test-dir /tmp/misra_ch15_lab --output-on-failure
```

El perfil `EQUIPO` debe construirse en un directorio de salida independiente. Esta comparación sirve para entender la importancia de identificar **qué configuración se ha verificado**.

### Código que no debe ejecutarse

Algunos ejemplos contienen errores deliberados: lecturas de objetos fuera de su tiempo de vida, carreras de datos, violaciones de la ODR, conversiones dependientes del hardware o expresiones con comportamiento indefinido. Los nombres `NO_EJECUTAR` y `NO_ENLAZAR` del capítulo 16 son avisos explícitos. 
Por ello, **no ejecutes estos fragmentos para comprobar que fallan**. Su estudio puede consistir simplemente en leerlos, compilar sin enlazar o contrastar un diagnóstico estático, según el caso.

Es importante destacar que el que un ejemplo compile, supere una prueba o no genere avisos **no demuestra conformidad MISRA**. La aplicación profesional del estándar requiere consultar su texto oficial, delimitar el sistema, aplicar los métodos de comprobación acordados y documentar las evidencias pertinentes.

## Libro, estándar y atribución

El libro ofrece explicaciones propias, código original y referencias a los identificadores de las pautas. **No reproduce ni pretende sustituir el estándar oficial**. Para aplicar MISRA C++:2023 en un proyecto profesional, consulta la edición autorizada en el sitio del consorcio: **https://misra.org.uk/**.

Esta es una publicación **independiente y no oficial**, sin afiliación, patrocinio ni respaldo de *The MISRA Consortium Limited*. Las marcas y los contenidos del estándar pertenecen a sus respectivos titulares.

## Licencias: código y libro

**Código del repositorio: licencia MIT.** Los ejemplos y las pruebas originales se distribuyen con una licencia permisiva que permite utilizar, modificar y redistribuir el código, incluso en proyectos comerciales, siempre que se conserven los avisos de copyright y licencia exigidos. 

**Texto del libro: Creative Commons Reconocimiento-NoComercial-CompartirIgual 4.0 Internacional (CC BY-NC-SA 4.0).** Esta licencia se aplica al contenido editorial original de la obra. Permite compartir y adaptar el texto con atribución, sin uso comercial y bajo la misma licencia para las adaptaciones. No se extiende al estándar MISRA ni a sus marcas. Puedes consultar las condiciones en **https://creativecommons.org/licenses/by-nc-sa/4.0/deed.es**.

Las dos licencias se aplican a materiales diferentes: **reutilizar un fragmento de código MIT no convierte el texto del libro en contenido MIT**, y la licencia CC del libro no modifica la licencia de los ejemplos. Los derechos de terceros deben respetarse en cualquier caso.

## Contribuciones y correcciones

Este proyecto está abierto a observaciones y propuestas de mejora. Si encuentras una explicación confusa o un error en un ejemplo, aporta el archivo, la versión del compilador, las opciones utilizadas y una descripción mínima del comportamiento observado. Si propones una alternativa, explica qué propiedad conserva y en qué condiciones es válida.

La obra reconoce la colaboración de herramientas de inteligencia artificial durante su elaboración, junto con la revisión humana de sus contenidos. Las contribuciones deberán ser originales o disponer de autorización suficiente para su publicación, y evitar incorporar código confidencial de terceros.

El objetivo de este repositorio es que **el código ayude a comprender el razonamiento del libro y que el libro ayude a interpretar el código**. Esperamos que resulte útil tanto para estudiar C++17 como para conversar con otros ingenieros sobre las decisiones que hacen un sistema más verificable y mantenible de acuerdo con estándares intenacionales como MISRA C++:2023.

