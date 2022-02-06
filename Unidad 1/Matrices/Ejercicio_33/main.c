#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 3
#define COL FIL

int main()
{
    int mat[FIL][COL] = {{-1,3,9},
                         {3,-1,4},
                         {9,4,-1}};

    mostrarMatriz(FIL, COL, mat);
    if(esMatrizSimetrica(FIL, COL, mat))
        printf("La matriz es simetrica.\n");
    else
        printf("La matriz NO es simetrica.\n");

}
