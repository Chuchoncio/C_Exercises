#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 3
#define COL FIL

int main()
{
    int mat1[FIL][COL] = {{1,2,3},{4,5,6},{7,8,9}};
    int mat2[FIL][COL] = {{9,8,7},{6,5,4},{3,2,1}};

    printf("Matriz 1:\n");
    mostrarMatriz(FIL, COL, mat1);

    printf("\n\nMatriz 2:\n");
    mostrarMatriz(FIL, COL, mat2);

    printf("\n\nMatriz Producto:\n");
    obtenerMatrizProducto(FIL, COL, mat1, mat2);

    return 0;
}
