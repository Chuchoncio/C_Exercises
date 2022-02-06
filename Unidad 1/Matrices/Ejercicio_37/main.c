#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define N 4

int main()
{
    int mat[N][N] = {{0,6,2,3},
                     {0,0,4,0},
                     {2,1,0,4},
                     {3,6,1,0}};

    if(!esMatrizPuntuacion(N, mat))
        printf("No es matriz puntuacion!\n");
    else
        printf("Es matriz puntuacion!\n");

    cantPuntosPorEquipo(N, mat);

    return 0;
}
