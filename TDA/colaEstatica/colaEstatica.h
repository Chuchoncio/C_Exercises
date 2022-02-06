#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define TAM_COLA 300

/* Disponemos de un vector cola, y dos unsigned que
    nos indican el inicio y final de la cola.
    Ademas de otro unsigned para indicar el tamaño
    disponible del vector.
 */

typedef struct
{
    char cola[TAM_COLA];
    unsigned pri,
             ult,
             tamDisp;
} tCola;

void crearCola(tCola *p);
int colaLlena(const tCola *p, unsigned tamInfo);
int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo);
int colaVacia(const tCola *p);
int sacarDeCola(tCola *p, void *info, unsigned tamInfo);
void vaciarCola(tCola *p);

#endif // COLAESTATICA_H_INCLUDED
