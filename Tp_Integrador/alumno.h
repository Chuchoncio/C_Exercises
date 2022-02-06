#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cadenas.h"

typedef struct {
    long dni;
    char apyn[40];
    t_fecha fecha_nac;
    char sexo;
    t_fecha fecha_ingreso;
    char carrera[4];
    int cant_mat_aprob;
    t_fecha fecha_aprob_ult;
    char estado;
    t_fecha fecha_baja;

} t_alumno;

int valida_alumno(const t_fecha *, t_alumno *); /// 0 si es valido | 1 si es invalido
int ingresa_alumno(t_alumno* alumno);
void normaliza_apellido_nombre(t_alumno* alumno);

#endif // ALUMNO_H_INCLUDED
