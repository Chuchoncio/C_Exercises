#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LARGOTEXTO 50

char *MiStrCpy(char *s1, const char *s2);
int MiStrCmpi(const void *s1, const void *s2);
size_t MiStrlen(const char *s);
char* cmpLxcg(char* cad1, char* cad2);

#endif // MAIN_H_INCLUDED
