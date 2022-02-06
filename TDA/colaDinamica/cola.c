#include "cola.h"

void crearCola(tCola *p)
{
    p->pri = NULL;
    p->ult = NULL;
}
int colaLlena(const tCola *p, unsigned tamInfo)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tamInfo);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int ponerEnCola(tCola *p, const void *info, unsigned tamInfo)
{
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));
    nue->info = malloc(tamInfo);

    if(nue == NULL || nue->info == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tamInfo);
    nue->tamInfo = tamInfo;
    nue->sig = NULL;
    if(p->ult)
        p->ult->sig = nue;
    else
        p->pri = nue;
    p->ult = nue;

    return 1;
}
int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo)
{
    if(p->pri == NULL)
        return 0;

    memcpy(info, p->pri->info, MINIMO(tamInfo, p->pri->tamInfo));

    return 1;
}

int colaVacia(const tCola *p)
{
    return p->pri == NULL;
}

int sacarDeCola(tCola *p, void *info, unsigned tamInfo)
{
    tNodo *aux = p->pri;
    if(aux == NULL)
        return 0;

    p->pri = aux->sig;
    memcpy(info, aux->info, MINIMO(aux->tamInfo, tamInfo));
    free(aux->info);
    free(aux);

    if(p->pri == NULL)
        p->ult = NULL;

    return 1;
}

void vaciarCola(tCola *p)
{
    while(p->pri)
    {
        tNodo *aux = p->pri;
        p->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    p->ult = NULL;
}
