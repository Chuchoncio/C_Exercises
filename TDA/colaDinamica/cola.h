#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X)<(Y)? (X) : (Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo * sig;
} tNodo;

typedef struct
{
    tNodo *pri,
          *ult;
} tCola;

void crearCola(tCola *p);
int colaLlena(const tCola *p, unsigned tamInfo);
int ponerEnCola(tCola *p, const void *info, unsigned tamInfo);
int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo);
int colaVacia(const tCola *p);
int sacarDeCola(tCola *p, void *info, unsigned tamInfo);
void vaciarCola(tCola *p);

#endif // COLA_H_INCLUDED
