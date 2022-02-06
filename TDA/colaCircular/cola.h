#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X) < (Y) ? (X) : (Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo * sig;
} tNodo;

typedef tNodo * tCola;

void crear_cola(tCola * pc);
int poner_en_cola(tCola * pc, const void * pd, unsigned tam);
int sacar_de_cola(tCola * pc, void * pd, unsigned tam);
int cola_vacia(const tCola * pc);

#endif // COLA_H_INCLUDED
