#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBREARCH "archtext.txt"

#define ESVOCAL(X)  ( (X) == 'A' || (X) == 'E' || (X) == 'I' \
                     || (X) == 'O' || (X) == 'U' || (X) == 'a' \
                     || (X) == 'e' || (X) == 'i' || (X) == 'o' \
                     || (X) == 'u' ? 0 : 1)

#define ESDIGITO(X) ( (X) >= 48 && (X) <= 57 ? 0 : 1 )

int MyStrCLen(char* cad, char c);
char* MyStrCCpy(char *s1, const char *s2, char c);

#endif // MAIN_H_INCLUDED
