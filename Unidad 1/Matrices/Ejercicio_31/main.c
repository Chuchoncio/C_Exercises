#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 3
#define COL 3

int main()
{
    int mat[FIL][COL] = {{2,0,0},
                         {0,2,0},
                         {0,0,2}};

    mostrarMatriz(FIL, COL, mat);

    if(esMatrizDiagonal(FIL, COL, mat)) // == 1
        puts("Su matriz es identidad");
    else
        puts("Su matriz NO es identidad");

    return 0;
}
