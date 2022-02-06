#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAMVEC 100

typedef struct {
    long suma;
    float promedio;
} calculosVector;

void ingresarVectorVariable(int vec[], int *tam);
float sumaYPromedio(int vec[], int tam, long *sumaElemVec);
void sumaYPromedioStruct(int vec[], int tam, calculosVector *calculo);

#endif // MAIN_H_INCLUDED
