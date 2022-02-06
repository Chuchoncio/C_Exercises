#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int factorialRecur(int n);
void mostrarVecRecur(char* cad);
void mostrarVecInvRecur(char* cad);
int sumaYMostrarVecRecur(char* cad);
int sumaYMostrarVecIntRecur(int* vec);
int sumaYMostrarVecIntParesRecur(int* vec);
int sumaYMostrarVecIntPosParRecur(int* vec);
int MyIntLen(int* vec);
char *MiStrchrRec(char *s, int c);
int MiStrlenRec(const char *s);
char *MiStrrchrRec(char *s, int c);

#endif // MAIN_H_INCLUDED
