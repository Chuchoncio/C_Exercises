#include "main.h"

void ingresarVectorVariable(int vec[], int *tam)
{
    int i;

    printf("Ingrese tamanio del vector: ");
    scanf("%d", tam);

    for(i = 0; i < *tam; i++)
    {
        printf("Ingrese elem: ");
        scanf("%d", &vec[i]);
    }
}

float sumaYPromedio(int vec[], int tam, long *sumaElemVec)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        *sumaElemVec += vec[i];
    }

    return (float)(*sumaElemVec) / tam;
}

void sumaYPromedioStruct(int vec[], int tam, calculosVector *calculo)
{
    int i;

    for(i = 0; i < tam; i++)
    {
       calculo->suma += vec[i];
    }

    calculo->promedio = (float)calculo->suma / tam;
}
