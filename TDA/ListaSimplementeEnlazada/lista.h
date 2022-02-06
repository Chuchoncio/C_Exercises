#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIN_MEM     1
#define CLA_DUP     2
#define TODO_BIEN   0

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;
typedef tNodo *tLista;

void crearLista(tLista *p);
int listaVacia(const tLista *p);
int listaLlena(const tLista *p, unsigned cantBytes);
void vaciarLista(tLista *p);
int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes);
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes);
int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes);
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes);
int verUltimoLista(const tLista *p, void *d, unsigned cantBytes);
int ponerOrdenLista(tLista * pl, const void *d, unsigned cantBytes, int(*cmp)(const void *, const void *));
int sacarElemLista(tLista * pl, void * pd,unsigned tam, int(*cmp)(const void*, const void*));
void recorrerLista(tLista *pl, void (*mostrar)(const void *));
int sacarElemOrdLista(tLista * pl, void * pd,unsigned tam, int(*cmp)(const void*, const void*));
void recorrerListaArch(tLista *pl, void (*accion)(void *, void *), void* param);
void ordenarSelLista(tLista * pl, int(*cmp)(const void*, const void*));
tNodo ** buscar_menor_nodo_lista(const tLista * pl, int(*cmp)(const void*, const void*));
void reinsertar_nodo_menor(tLista * pl, tLista * men);
void intercambiar_info_nodos(tLista * n1, tLista * n2);

#endif // LISTA_H_INCLUDED
