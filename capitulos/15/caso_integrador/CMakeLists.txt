cmake_minimum_required(VERSION 3.16)
project(capitulo15_evidencias LANGUAGES CXX)

if(NOT DEFINED CH15_VARIANTE)
    message(FATAL_ERROR "Indicar -DCH15_VARIANTE=LABORATORIO o EQUIPO")
endif()

if(NOT CH15_VARIANTE STREQUAL "LABORATORIO" AND
   NOT CH15_VARIANTE STREQUAL "EQUIPO")
    message(FATAL_ERROR "Variante de producto desconocida")
endif()

add_library(adquisicion STATIC src/sensor.cpp src/adquisicion.cpp)
target_include_directories(adquisicion PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(adquisicion PUBLIC cxx_std_17)
set_target_properties(adquisicion PROPERTIES CXX_EXTENSIONS OFF)

if(CH15_VARIANTE STREQUAL "LABORATORIO")
    target_compile_definitions(adquisicion PUBLIC CH15_VARIANTE_LABORATORIO=1)
else()
    target_compile_definitions(adquisicion PUBLIC CH15_VARIANTE_EQUIPO=1)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(adquisicion PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

add_executable(pruebas_adquisicion pruebas/pruebas_adquisicion.cpp)
target_link_libraries(pruebas_adquisicion PRIVATE adquisicion)
include(CTest)
add_test(NAME adquisicion_correcta COMMAND pruebas_adquisicion)

add_executable(pruebas_ejemplos ../pruebas/pruebas_ejemplos.cpp)
target_compile_features(pruebas_ejemplos PRIVATE cxx_std_17)
set_target_properties(pruebas_ejemplos PROPERTIES CXX_EXTENSIONS OFF)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(pruebas_ejemplos PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()
add_test(NAME ejemplos_seguros COMMAND pruebas_ejemplos)
