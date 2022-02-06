#include <stdio.h>
#include <stdlib.h>
#include <matrices.h>

#define FIL 10
#define COL 10

int main()
{
    int mat[FIL][COL];

    generarMatriz(FIL, COL, mat);
    mostrarMatriz(FIL, COL, mat);

    printf("Traza de la matriz: %d\n", sumaDiagPrinc(FIL, COL, mat));
    printf("Traza secundaria de la matriz: %d\n", sumaDiagSecu(FIL, COL, mat));

    return 0;
}
