#ifndef GUIA_MISRA_CONFIGURACION_EQUIPO_HPP
#define GUIA_MISRA_CONFIGURACION_EQUIPO_HPP

#define MODO_LABORATORIO 1
#define MODO_CAMPO 2

#if !defined(MODO_EQUIPO)
#error "Debe definirse MODO_EQUIPO en la construccion"
#elif (MODO_EQUIPO != MODO_LABORATORIO) && (MODO_EQUIPO != MODO_CAMPO)
#error "MODO_EQUIPO debe valer 1 o 2"
#endif

#endif
