#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

int main()
{
    int elem = 1,
        i = 0,
        ent_elim = 0;
    tPila pila_ent;
    crear_pila(&pila_ent);

    for(i = 0; i < 26; i++)
    {
        int r = poner_en_pila(&pila_ent, &i, sizeof(i));
        if(!r)
            printf("Pila llena!\n");
    }

    system("pause");

    ver_tope_pila(&pila_ent, &elem, sizeof(elem));
    printf("\nTope de pila: %d", elem);

    sacar_de_pila(&pila_ent, &ent_elim, sizeof(elem));
    printf("\nSacamos un elemento de la pila...");
    ver_tope_pila(&pila_ent, &elem, sizeof(elem));
    printf("\nTope de pila: %d", elem);

    printf("\n Vaciando pila...");
    vaciar_pila(&pila_ent);


    return 0;
}
