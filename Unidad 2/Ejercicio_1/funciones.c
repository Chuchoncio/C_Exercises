#include "main.h"

void grabarVecEnArch(float vec[], int cantElem)
{
    FILE *arch;

    arch = fopen("Vector_Flotantes.txt", "wt");

    if(!arch)
    {
        printf("\nError en archivo.");
        exit(1);
    }

    while(*vec && cantElem > 0)
    {
        fprintf(arch, "%f\n", *vec);
        vec++;
        cantElem--;
    }

    fclose(arch);
}

void mostrarOrdenInverso(float vec[], int cantElem)
{
    vec += cantElem-1;
    while(*vec && cantElem > 0)
    {
        printf("[%.3f]", *vec);
        vec--;
        cantElem--;
    }
}

void mostrarVector(float vec[], int cantElem)
{
    while(*vec && cantElem > 0)
    {
        printf("[%.3f]", *vec);
        vec++;
        cantElem--;
    }
}

float calcularPromedioPosPar(float vec[], int cantElem)
{
    float sumaPosPar = 0;
    int cantElemPosPar = 0, i;

    for(i = 0; i < cantElem; i++)
    {
        if(i%2 == 0)
        {
            sumaPosPar += vec[i];
            cantElemPosPar++;
        }
    }

    return sumaPosPar / cantElemPosPar;
}

float buscarMinimo(float vec[], int cantElem)
{
    float minElem = *vec,
          compNumVec, compNumMin;

    vec++;

    while(*vec && cantElem > 1)
    {
        compNumVec = (*vec) * 100;
        compNumMin = minElem * 100;

        if((int)compNumVec < (int)compNumMin)
            minElem = *vec;

        vec++;
        cantElem--;
    }

    return minElem;
}

int ingresarVector(float vec[], int cantElemMax)
{
    int cantElemIng = 0;

    while(cantElemMax > 0)
    {
        printf("Ingrese elemento: ");
        scanf("%f", vec);

        vec++;
        cantElemIng++;
        cantElemMax--;
    }

    return cantElemIng;
}
