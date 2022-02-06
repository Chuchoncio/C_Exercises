#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    tCola cola1;
    int i, elem;

    crearCola(&cola1);

    for(i = 0; i < 10; i++)
    {
        ponerEnCola(&cola1, &i, sizeof(i));
    }

    while(!colaVacia(&cola1))
    {
        sacarDeCola(&cola1, &elem, sizeof(elem));
        printf("El elemento es: %d\n", elem);
    }

    return 0;
}
