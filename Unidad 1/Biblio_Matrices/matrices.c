#include "matrices.h"

void generarMatriz(int fil, int col, int mat[][col])
{
    for(int i = 0 ; i < fil ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            // mat[i][j] = rand() % (N-M+1) + M -> M = cota inferior , N = cota superior
            mat[i][j] = rand() % (20-5+1) + 5;
        }
    }
}

void mostrarMatriz(int fil, int col, int mat[][col])
{
    for(int i = 0 ; i < fil ; i++)
    {
        for(int j = 0 ; j < col ; j++)
            printf("[%3d]",mat[i][j]);
        puts("\n");
    }
}

int sumatoriaEncimaDiagPrincipal(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i < j)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumatoriaEncimaConDiagPrincipal(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i <= j)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumatoriaDebajoDiagPrincipal(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i > j)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumatoriaEncimaDiagSecundaria(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if((i+j) < col-1)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumatoriaEncimaConDiagSecundaria(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if((i+j) < col)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumatoriaDebajoDiagSecundaria(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if((i+j) > col-1)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumaDiagPrinc(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
                suma += mat[i][j];
        }
    }

    return suma;
}

int sumaDiagSecu(int fil, int col, int mat[][col])
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if((i+j) == col-1)
                suma += mat[i][j];
        }
    }

    return suma;
}

int esMatrizDiagonal(int fil, int col, int mat[][col])
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i != j && mat[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

// Determinar si una matriz cuadrada es identidad
int esMatrizIdentidad(int fil, int col, int mat[][col])
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if( (i != j && mat[i][j] != 0) || (i == j && mat[i][j] != 1) )
                return 0;
        }
    }

    return 1;

}

// Determinar si una matriz cuadrara de enteros es simetrica
int esMatrizSimetrica(int fil, int col, int mat[][col])
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(!(mat[i][j] == mat[j][i]))
                return 0;
        }
    }
    return 1;
}

// Trasponer una matriz (in situ)
void trasponerMatriz(int fil, int col, int mat[][col])
{
    int i, j;

    for(i = 0; i < fil; i++)
    {
        for(j = 0; j < col; j++)
            printf("[%d]",mat[j][i]);
        printf("\n");
    }
}

void obtenerTraspuesta(int fil, int col, int mat[][col])
{
    int i, j, aux;
    for(i = 0; i < fil; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(j < i)
            {
                aux = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = aux;
            }
        }
    }

    mostrarMatriz(fil, col, mat);
}

void obtenerMatrizProducto(int fil, int col, int mat1[][col], int mat2[][col])
{
    int matProd[fil][col];
    int i, j, k;
    int suma = 0;

    for(i = 0; i < fil; i++)
    {
        for(j = 0; j < col; j++)
        {
            suma = 0;
            for(k = 0; k < col; k++)
            {
                 suma += mat1[i][k] * mat2[k][j];
            }
            matProd[i][j] = suma;
        }
    }

    mostrarMatriz(fil, col, matProd);
}

int esMatrizPuntuacion(int orden, int mat[][orden])
{
    int i, j;

    for(i = 0; i < orden; i++)
    {
        for(j = 0; j < orden; j++)
        {
            if(i == j)
                continue;
            if((mat[i][j] == 4 && mat[j][i] != 1) || (mat[i][j] == 1 && mat[j][i] != 4))
                return 0;
            if((mat[i][j] == 6 && mat[j][i] != 0) || (mat[i][j] == 0 && mat[j][i] != 6))
                return 0;
            if((mat[i][j] == 2 && mat[j][i] != 2) || (mat[i][j] == 3 && mat[j][i] != 3))
                return 0;
        }
    }
    return 1;
}

void cantPuntosPorEquipo(int orden, int mat[][orden])
{
    if(!esMatrizPuntuacion(orden, mat))
    {
        printf("\nError! Matriz incorrecta.\n");
        return ;
    }

    int vecTotPunt[orden], i, j;

    for(i = 0; i < orden; i++)
    {
        vecTotPunt[i] = 0;
        for(j = 0; j < orden; j++)
        {
            if(i == j)
                continue;

            vecTotPunt[i] += mat[i][j];
        }
    }

    printf("\n--Puntuaciones--\n\n");
    for(i = 0; i < orden; i++)
        printf("Equipo %d - %2d puntos\n", i+1, vecTotPunt[i]);
}


