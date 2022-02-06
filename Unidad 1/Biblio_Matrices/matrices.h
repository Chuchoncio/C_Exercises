#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void generarMatriz(int fil, int col, int mat[][col]);
void mostrarMatriz(int fil, int col, int mat[][col]);
int sumatoriaEncimaDiagPrincipal(int fil, int col, int mat[][col]);
int sumatoriaEncimaConDiagPrincipal(int fil, int col, int mat[][col]);
int sumatoriaDebajoDiagPrincipal(int fil, int col, int mat[][col]);
int sumatoriaEncimaDiagSecundaria(int fil, int col, int mat[][col]);
int sumatoriaEncimaConDiagSecundaria(int fil, int col, int mat[][col]);
int sumatoriaDebajoDiagSecundaria(int fil, int col, int mat[][col]);
int sumaDiagPrinc(int fil, int col, int mat[][col]);
int sumaDiagSecu(int fil, int col, int mat[][col]);
int esMatrizDiagonal(int fil, int col, int mat[][col]);
int esMatrizIdentidad(int fil, int col, int mat[][col]);
int esMatrizSimetrica(int fil, int col, int mat[][col]);
void trasponerMatriz(int fil, int col, int mat[][col]);
void obtenerTraspuesta(int fil, int col, int mat[][col]);
void obtenerMatrizProducto(int fil, int col, int mat1[][col], int mat2[][col]);
int esMatrizPuntuacion(int orden, int mat[][orden]);
void cantPuntosPorEquipo(int orden, int mat[][orden]);

#endif // MATRICES_H_INCLUDED
