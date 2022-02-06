#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMVEC 100

void menuOpciones();
int ingresarVector(float vec[], int cantElemMax);
float buscarMinimo(float vec[], int cantElem);
float calcularPromedioPosPar(float vec[], int cantElem);
void mostrarVector(float vec[], int cantElem);
void mostrarOrdenInverso(float vec[], int cantElem);
void grabarVecEnArch(float vec[], int cantElem);

#endif // MAIN_H_INCLUDED
