#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(x,y) ( (x) < (y) ? (x) : (y) )

/* La estructura dinamica posee el dato, el tamaño
    del dato y un puntero tipo sNodo que apunta al
    siguiente dato de la pila (cumple la funcion de
    parecerse a un vector).
 */
typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tPila; // Este es el apodo que se le da a la estructura
                      // tipo tNodo para trabajar mas comodo

int ver_tope_pila(const tPila * pp, void * info, unsigned tam);
void crear_pila(tPila * pp);
int poner_en_pila(tPila * pp, const void * info, unsigned tam);
int pila_vacia(const tPila * pp);
int pila_llena(const tPila * pp, unsigned tam);
int sacar_de_pila(tPila * pp, void * info, unsigned tam);
void vaciar_pila(tPila * pp);

#endif // PILADINAMICA_H_INCLUDED
