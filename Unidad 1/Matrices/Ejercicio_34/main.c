#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 3
#define COL FIL

int main()
{
    int mat[FIL][COL] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};

    mostrarMatriz(FIL, COL, mat);
    printf("\n Matriz traspuesta: \n");
    trasponerMatriz(FIL, COL, mat);
}
