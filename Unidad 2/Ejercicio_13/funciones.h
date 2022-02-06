#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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

int cargarEstudiantes(char* pathArchEst);
int cargarEmpleados(char* pathArchEmp);
int leerArchivoEmpleados(char* pathArchEmp);

#endif // FUNCIONES_H_INCLUDED
