#include "pilaDinamica.h"

void crear_pila(tPila * pp)
{
    *pp = NULL; // Inicializamos el puntero en NULL
}

int pila_vacia(const tPila * pp)
{
    return *pp == NULL; // Verifica si la pila apunta a NULL
}

int pila_llena(const tPila * pp, unsigned tam)
{
    tPila * vnodo = malloc(sizeof(tam)); // Genera un puntero tipo tPila con memoria dinamica
    void * info = malloc(tam); // Genera un valor de tipo void porque es la manera generica
                               // de introducir datos en la pila

    free(vnodo); // Liberas la memoria del nodo
    free(info); // Liberas la memoria del dato

    return vnodo == NULL || info == NULL;   // Verifica si alguno de los dos genero algun error,
                                            // si fue asi, retorna true
}

int poner_en_pila(tPila * pp, const void * info, unsigned tam)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));   // Genera un nodo con memoria dinamica
                                                    // y lo convierte a tipo tNodo

    if(!nue) // Verifica si el nodo se creo correctamente (si la pila esta llena)
        return 0;

    nue->info = malloc(tam); // Genera espacio con memoria dinamica (malloc por defecto
                             // lo crea tipo void)
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tam; // Asigna el tamaño pasado al elemento de la pila
    nue->sig = *pp; // Apunta a la pila (dato por desreferencia)
    memcpy(nue->info, info, tam); // Se transfiere la informacion

    *pp = nue; // Ahora pila apunta al nuevo nodo creado
    return 1;
}

int sacar_de_pila(tPila * pp, void * info, unsigned tam)
{
    tNodo * elim = *pp; // Crea un nodo que apunta a la pila (al dato por la desreferencia)
    if(!*pp) // Verifica si la pila esta vacia
        return 0;

    memcpy(info, elim->info, MINIMO(elim->tamInfo, tam)); // Transfiere el elemento a borrar
    *pp = elim->sig; // La pila ahora apunta al elemento siguiente

    free(elim->info); // Se libera la informacion del nodo actual
    free(elim); // Se libera el nodo actual
    return 1;
}

int ver_tope_pila(const tPila * pp, void * info, unsigned tam)
{
    tNodo * topeElem = *pp; // Se crea un nodo que apunta al ultimo elemento de la pila
    if(!*pp) // Verifica si la pila no esta vacia
    {
        printf("\nPila vacia!");
        return 0;
    }

    memcpy(info, topeElem->info, MINIMO(topeElem->tamInfo, tam)); // Transfiere  datos a info
                                                                  // verificando si es minimo

    return 1;
}

void vaciar_pila(tPila * pp)
{
    while(*pp)  // Mientras exista un dato, va a seguir generando un auxiliar para borrarlo
    {
        tNodo * elimPila = *pp; // El asterisco indica un nivel de referencia mas para apuntar a un Nodo
        *pp = elimPila->sig;
        free(elimPila->info);
        free(elimPila);
    }
}
