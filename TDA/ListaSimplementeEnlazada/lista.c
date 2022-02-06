#include "lista.h"

#define MINIMO(X,Y) ( (X) < (Y) ? (X) : (Y) )

void crearLista(tLista *p)
{
    *p = NULL;
}

int listaVacia(const tLista *p)
{
    return *p == NULL;
}

int listaLlena(const tLista *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

void vaciarLista(tLista *p)
{
    while(*p)
    {
        tNodo *aux = *p;

        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo *nue;

    if( (nue = (tNodo*)malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL )
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;

    return 1;
}
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if(aux == NULL)
        return 0;

    *p = aux->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);

    return 1;
}

int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;

    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));

    return 1;
}

int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo *nue;

    while(*p)
        p = &(*p)->sig;

    if( (nue = (tNodo*)malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy((*p)->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *p = nue;

    return 1;
}

int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;

    while(*p)
        p = &(*p)->sig;

    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    free((*p)->info);
    free(*p);

    *p = NULL;

    return 1;
}

int verUltimoLista(const tLista *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;

    while((*p)->sig)
        p = &(*p)->sig;

    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));

    return 1;
}

int ponerOrdenLista(tLista * pl, const void *pd, unsigned cantBytes, int(*cmp)(const void *, const void *))
{
    tNodo * nue;
    int rc;

    while(*pl && (rc=cmp(pd, (*pl)->info)) > 0)
        pl = &(*pl)->sig;


    if(*pl && !rc)
        return 0; //Duplicado

    nue = (tNodo*)malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(cantBytes);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = cantBytes;
    memcpy(nue->info, pd, cantBytes);
    nue->sig = *pl;
    *pl = nue;

    return 1;
}

int sacarElemLista(tLista * pl, void * pd,unsigned tam, int(*cmp)(const void*, const void*))
{
    tNodo * elim;

    while( *pl && cmp(pd, (*pl)->info) != 0)
        pl = &(*pl)->sig;

    if(!*pl)
        return 0;

    elim = *pl;
    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));

    *pl = elim->sig;
    free(elim->info);
    free(elim);

    return 1;
}

int sacarElemOrdLista(tLista * pl, void * pd,unsigned tam, int(*cmp)(const void*, const void*))
{
    tNodo * elim;
    int rc;

    while( *pl && (rc = cmp(pd, (*pl)->info)) > 0)
        pl = &(*pl)->sig;

    if(!*pl || rc)
        return 0;

    elim = *pl;
    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));

    *pl = elim->sig;
    free(elim->info);
    free(elim);

    return 1;
}

void recorrerLista(tLista *pl, void (*mostrar)(const void *))
{
    while(*pl)
    {
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }
}

void recorrerListaArch(tLista *pl, void (*accion)(void *, void *), void* param)
{
    while(*pl)
    {
        accion((*pl)->info, param);
        pl = &(*pl)->sig;
    }
}

void ordenarSelLista(tLista * pl, int(*cmp)(const void*, const void*))
{
    if(!*pl)
        return ;

    while( (*pl)->sig )
    {
        tNodo ** men = buscar_menor_nodo_lista(pl, cmp);
        if( pl != men )
        {
            intercambiar_info_nodos(pl, men);
            reinsertar_nodo_menor(pl, men);
        }
        pl = &(*pl)->sig;
    }
}

tNodo ** buscar_menor_nodo_lista(const tLista * pl, int(*cmp)(const void*, const void*))
{
    const tLista * men = pl;
    if(!*pl)
        return NULL;

    pl = &(*pl)->sig;

    while(*pl)
    {
        if(cmp((*pl)->info, (*men)->info) < 0)
        {
            men = pl;
        }
        pl = &(*pl)->sig;
    }

    return (tNodo **)men;
}

void reinsertar_nodo_menor(tLista * pl, tLista * men)
{
    tNodo * aux = *men;
    *men = aux->sig;

    aux->sig = *pl;
    *pl = aux;
}

void intercambiar_info_nodos(tLista * n1, tLista * n2)
{
    unsigned aux_tam;
    void * aux = (*n1)->info;
    (*n1)->info = (*n2)->info;
    (*n2)->info = aux;

    aux_tam = (*n1)->tamInfo;
    (*n1)->tamInfo = (*n2)->tamInfo;
    (*n2)->tamInfo = aux_tam;
}
