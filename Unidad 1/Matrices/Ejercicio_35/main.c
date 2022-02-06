#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 3
#define COL FIL

int main()
{
    int mat[FIL][COL] = {{1,3,4},
                         {8,5,7},
                         {5,21,33}};

    mostrarMatriz(FIL, COL, mat);
    printf("Matriz Traspuesta: \n");
    obtenerTraspuesta(FIL, COL, mat);

    return 0;
}
