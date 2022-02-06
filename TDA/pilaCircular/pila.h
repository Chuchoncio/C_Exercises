#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X) < (Y) ? (X) : (Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tPila;

void crear_pila(tPila * pp);
int poner_en_pila(tPila * pp, const void * pd, unsigned tam);
int sacar_de_pila(tPila * pp, void * pd, unsigned tam);
int pila_vacia(const tPila * pp);
int pila_llena(const tPila * pp, unsigned tamDato);

#endif // PILA_H_INCLUDED
