#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define MALA_APERTURA 1

typedef struct
{
    int dni;
    char apellido[15],
         nombre[15];
    double sueldo;
} t_empleado;

typedef struct
{
    int dni;
    char apellido[15],
         nombre[15];
    float promedio;
} t_estudiante;

int cargarEmpleados(char* pathArchEmp);
int cargarEstudiantes(char* pathArchEst);
int leerArchivoEmpleados(char* pathArchEmp);

#endif // MAIN_H_INCLUDED
