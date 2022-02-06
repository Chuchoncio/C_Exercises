#include "main.h"

int main()
{
    char **mtxLineas;
    char cad1[LARGOTEXTO], cad2[LARGOTEXTO];
    int lonCad1, lonCad2, condicionPar = 1, i = 0,
        opcion, cantPares = 0;

    mtxLineas = (char**)malloc(LARGOTEXTO);

    while(condicionPar)
    {
        printf("Introduce par cadena 1: ");
        gets(cad1);
        fflush(stdin);        printf("Introduce par cadena 2: ");
        gets(cad2);
        fflush(stdin);

        *(mtxLineas+i) = (char*)malloc(LARGOTEXTO+1);
        *(mtxLineas+i+1) = (char*)malloc(LARGOTEXTO+1);

        lonCad1 = MiStrlen(cad1);
        lonCad2 = MiStrlen(cad2);

        if(lonCad1 < lonCad2)
            opcion = 1;
        else if(lonCad2 < lonCad1)
            opcion = 2;
        else
        {
            if( MiStrCmpi(cad1, cmpLxcg(cad1, cad2)) == 0)
                opcion = 1;
            else
                opcion = 2;
        }

        switch(opcion)
        {
            case 1: MiStrCpy(mtxLineas[i],cad1);
                    MiStrCpy(mtxLineas[i+1],cad2);
                    break;
            case 2: MiStrCpy(mtxLineas[i],cad2);
                    MiStrCpy(mtxLineas[i+1],cad1);
                    break;
        }

        i+=2;
        cantPares+=2;

        if(lonCad1 == lonCad2)
            condicionPar = 0;
    }

    for(i = 0; i < cantPares; i++)
        printf("%s\n",*(mtxLineas+i));

    return 0;
}


