#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para usar isspace
#include <string.h>

#define CANTLINEAS
#define NOMBREARCH "archtext.txt"

void generarArchivo();
void agregarTexto();
char* Mystrstr(const char *s1, const char *s2, int* pos);

#endif // MAIN_H_INCLUDED
