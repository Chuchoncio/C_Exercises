#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define FIL 4
#define COL 4

int main()
{
    int mat[FIL][COL];

    generarMatriz(FIL, COL, mat);
    mostrarMatriz(FIL, COL, mat);

    printf("La sumatoria de los elementos por encima de la diagonal"
           " principal es: %d\n", sumatoriaEncimaDiagPrincipal(FIL, COL, mat));

    printf("La sumatoria de los elementos por encima de la diagonal"
           " principal (incluyendola) es: %d\n", sumatoriaEncimaConDiagPrincipal(FIL, COL, mat));

    printf("La sumatoria de los elementos por debajo de la diagonal"
           " principal es: %d\n", sumatoriaDebajoDiagPrincipal(FIL, COL, mat));

    printf("La sumatoria de los elementos por encima de la diagonal"
           " secundaria es: %d\n", sumatoriaDebajoDiagSecundaria(FIL, COL, mat));

    printf("La sumatoria de los elementos por encima de la diagonal"
           " secundaria (incluyendola) es: %d\n", sumatoriaEncimaConDiagSecundaria(FIL, COL, mat));

    printf("La sumatoria de los elementos por debajo de la diagonal"
           " secundaria es: %d\n", sumatoriaDebajoDiagSecundaria(FIL, COL, mat));



    return 0;
}
