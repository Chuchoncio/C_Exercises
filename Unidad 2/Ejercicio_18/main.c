#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../TDA/pilaDinamica/pilaDinamica.h"

int main()
{
    tPila pilita;
    FILE *arch;
    char buffer[1000], *pBuffer;
    int tamBuffer, cantL;

    arch = fopen("archPalabras.txt", "wt");

    if(!arch)
    {
        printf("Error de archivo\n");
        exit(1);
    }

    crear_pila(&pilita);

    printf("Ingrese la cantidad de letras: ");
    scanf("%d", &cantL);

    fflush(stdin);
    printf("Ingrese una cadena: ");
    gets(buffer);

    do
    {
        pBuffer = buffer;
        tamBuffer = strlen(pBuffer);

        if(tamBuffer >= cantL)
            poner_en_pila(&pilita, pBuffer, tamBuffer);

        while(*pBuffer)
        {
            printf("%c",*pBuffer+1);
            pBuffer++;
        }

        fflush(stdin);
        printf("\nIngrese una cadena: ");
        gets(buffer);
    }while(tamBuffer < 1000 && !strchr(buffer,'.'));

    memset(buffer,0,strlen(buffer));

    while(sacar_de_pila(&pilita, buffer, 100))
    {
        fprintf(arch, "%s\n", buffer);
        memset(buffer,0,strlen(buffer));
    }

    fclose(arch);

    return 0;
}
