#ifndef ARCHIVOSS_H_INCLUDED
#define ARCHIVOSS_H_INCLUDED

#include <stdio.h>
#include "cadenas.h"
#include "alumno.h"

void grabar_binario(FILE* arch_bin, t_alumno* alumno);
void grabar_error(FILE* arch_error, const char* cadena_txt);
int texto_a_alumno(const char* cadena_txt, t_alumno* alumno, t_fecha* fecha_proceso);
void muestra_binario(const char* nombre_archivo);

#endif // ARCHIVOSS_H_INCLUDED
