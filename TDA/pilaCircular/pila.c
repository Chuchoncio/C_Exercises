#include "pila.h"

void crear_pila(tPila * pp)
{
    *pp = NULL;
}

int poner_en_pila(tPila * pp, const void * pd, unsigned tam)
{
    tNodo* nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tam;
    memcpy(nue->info, pd, tam);

    if(!*pp)
        *pp = nue;
    else
        nue->sig = (*pp)->sig;

    (*pp)->sig = nue;
    return 1;
}

int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    tNodo* elim;

    if(!*pp)
        return 0;

    elim = (*pp)->sig;
    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));

    if (elim->sig == elim)
        *pp = NULL;
    else
        (*pp)->sig = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int pila_vacia(const tPila * pp)
{
    return !*pp;
}

int pila_llena(const tPila * pp, unsigned tamDato)
{
    return 1;
}
