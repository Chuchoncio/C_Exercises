#include "funciones.h"

int menuMsjOpc(const char *msj, const char *opc)
{
    char opta;
    int primeraVez = 1;

    do{
        if(!primeraVez)
            printf("\n Opcion Invalida, ingrese una nueva opcion \n");

        primeraVez = 0;
        printf("%s", msj);
        printf("\n Ingrese la opcion deseada del menu: \n");
        fflush(stdin);
        scanf("%c", &opta);
        opta=toupper(opta);
    }while(strchr(opc, opta) == NULL);

    return opta;
}
