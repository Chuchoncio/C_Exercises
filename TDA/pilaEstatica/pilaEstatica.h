#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define MINIMO(X, Y) ((X)<(Y)?(X):(Y))
#define TAM_PILA 200

/* La implementacion estatica nos garantiza tener una pila
    que no sobrepase cierta capacidad. Es mas segura dado
    que no corre el riesgo de sobrepasar la memoria disponible
    en el sistema.
 */
typedef struct{
    char pila[TAM_PILA]; // Donde se guardan los datos
    unsigned tope; // Indicador de capacidad
} tPila;

int ver_tope_pila(const tPila * pp, void * info, unsigned tam);
void crear_pila(tPila * pp);
int poner_en_pila(tPila * pp, const void * info, unsigned tam);
int pila_vacia(const tPila * pp);
int pila_llena(const tPila * pp, unsigned tam);
int sacar_de_pila(tPila * pp, void * info, unsigned tam);
void vaciar_pila(tPila * pp);


#endif // PILAESTATICA_H_INCLUDED
