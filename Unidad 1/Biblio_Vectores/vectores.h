#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mostrarVector(int* v, int ce);
char aMinuscula(char c);
void insertarEnVector(int* vec, int elem, int pos, int* ce, int tam);
int vectorLleno(int* vec, int ce);
void intercambiar(int* a, int* b);
int* buscarMenor(int* v, int* desde, int* hasta);
void insertarEnVectorYOrdenarAsc(int* vec, int* elem, int* ce, int tam);
void elimPosDeVector(int* vec, int* ce, int pos);
void elimPrimApari(int* vec, int elem, int* ce, int tam);
void elimTodasApari(int* vec, int elem, unsigned int* ce);
int determinarPalindromo(char* frase);
int valorNumericoCadena(char* cad);
int buscarLetra(char letra, char* cad);

#endif // VECTORES_H_INCLUDED
