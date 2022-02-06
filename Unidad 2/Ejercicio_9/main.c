#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *pf;
    short int elem;
    int cantElem1, cantLineasAlm;
    bool cond[2] = {false, false};

    pf = fopen("datos.txt", "wt");

    do
    {
        cantLineasAlm = 1;
        cantElem1 = rand () % (7-1+1) + 1;
        printf("Se van a ingresar %d numeros\n", cantElem1);

        if(cantElem1 == 7)
            cond[0] = true;
        if(cantElem1 == 1)
            cond[1] = true;

        if(cond[0] && cond[1])
            cantLineasAlm = rand () % (7-1+1) + 1;

        while(cantLineasAlm > 0)
        {
            while(cantElem1 > 0)
            {
                printf("Ingrese elem: ");
                scanf("%hi", &elem);
                fflush(stdin);

                fprintf(pf, "%6hi ", elem);
                cantElem1--;
            }
            cantLineasAlm--;
        }

        fprintf(pf, "\n");
        fflush(stdin);
    }
    while(!cond[0] || !cond[1]);

    fclose(pf);

    return 0;
}
