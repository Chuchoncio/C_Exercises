#include "pilaEstatica.h"

void crear_pila(tPila * pp)
{
    pp->tope = TAM_PILA; // Capacidad total: 200 posiciones
}

int pila_vacia(const tPila * pp)
{
    return pp->tope == TAM_PILA; // La pila esta vacia si es igual a la capacidad inicial
}

int pila_llena(const tPila * pp, unsigned tam)
{
    return pp->tope < tam + sizeof(unsigned); // Verifica si alcanza la capacidad para meter un dato mas
}

void vaciar_pila(tPila * pp)
{
    pp->tope = TAM_PILA; // Vaciar pila pisandole las posiciones ya cargadas
}

int poner_en_pila(tPila * pp, const void * info, unsigned tam)
{
    if(pp->tope < tam+sizeof(unsigned) ) // Verifica si la pila no esta llena
        return 0;

    pp->tope-=tam; // A tope le restamos el tamaño del elemento a insertar
    memcpy(pp->pila + pp->tope, info, tam); // Coloca los datos desde el final del vector hacia el inicio
    pp->tope -= sizeof(unsigned); // A tope le restamos el tamaño de la variable tam
    memcpy(pp->pila + pp->tope, &tam, sizeof(unsigned)); // Y colocamos los datos del tamaño de tam en la pila
    return 1;
}

int sacar_de_pila(tPila * pp, void * info, unsigned tam)
{
    unsigned tamInfo;

    if(pp->tope == TAM_PILA) // Verifica si la pila esta llena
        return 0;

    memcpy(&tamInfo, pp->pila + pp->tope, sizeof(unsigned)); // Extraemos el tamaño del elemnto primero
    pp->tope += sizeof(unsigned); // Quitamos del indicador de capacidad el tamaño de tam primero
    memcpy(info, pp->pila + pp->tope, MINIMO(tam, tamInfo));  // Saco de la pila el elemento con el tamaño minimo
    pp->tope += tamInfo; // Por ultimo, se quita del tope el tamaño de la info
    return 1;
}

int ver_tope_pila(const tPila * pp, void * info, unsigned tam)
{
    unsigned tamInfo;

    if(pp->tope == TAM_PILA)
        return 0;

    memcpy(&tamInfo, pp->pila + pp->tope, sizeof(unsigned)); // Se copia de la pila el tamaño del elemento
    memcpy(info, pp->pila + pp->tope + sizeof(unsigned),
           MINIMO(tam, tamInfo)); // Extraigo el elemento con el menor tamaño y el que esta mas cerca del inicio del vector

    return 1;

}

