#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* mayusculasMinusculas(char* s);
char* coma(char* s);
char* no_mas_de_un_espacio(char* s);
char* sin_espacios_inicio_fin(char* s);
int cantidad_apariciones(const char* s, char c);

#endif // CADENAS_H_INCLUDED
