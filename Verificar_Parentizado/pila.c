#include "pila.h"

void crearPila(Pila *ps)
{
    ps->top = -1;
}

int pilaVacia(Pila *ps)
{
    return ps->top == -1;
}

int pilaLlena(Pila *ps)
{
    return ps->top == STACKSIZE-1;
}

int sacarDePila(Pila *ps)
{
    if(ps->top == -1)
        return 1;

    return ps->items[ps->top--];
}

void ponerEnPila(Pila *ps, int x)
{
    if(ps->top == STACKSIZE-1)
    {
        printf("Pila llena!\n");
        return ;
    }

    ps->items[++ps->top] = x;
}

int verTope(Pila *ps)
{
    if(ps->top == -1)
        return 1;

    return ps->items[ps->top];
}

void vaciarPila(Pila *ps)
{
    ps->top = -1;
}
