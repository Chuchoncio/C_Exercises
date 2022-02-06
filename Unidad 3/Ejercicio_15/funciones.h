#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
int leerArchivoEstudiantes(char* pathArchEst);
int compararEstudiantes(const void* est1, const void* est2);
int compararEmpleados(const void* emp1, const void* emp2);
void actualizarArchivoEst(tLista* listaEst, char* pathArch);
void actualizarArchivoEmp(tLista* listaEmp, char* pathArch);
void cargarListaEstudiantes(char* pathArch, tLista* lista);
void cargarListaEmpleados(char* pathArch, tLista* listaEmp);
void ordenarListaEmp(tLista* listaEmp1);

#endif // FUNCIONES_H_INCLUDED
