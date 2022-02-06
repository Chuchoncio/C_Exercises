#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
typedef struct {
    int top;
    int items[STACKSIZE];
} Pila;

void crearPila(Pila *ps);
int pilaVacia(Pila *ps);
int pilaLlena(Pila *ps);
int sacarDePila(Pila *ps);
void ponerEnPila(Pila *ps, int x);
int verTope(Pila *ps);
void vaciarPila(Pila *ps);

#endif // PILA_H_INCLUDED
