#include "macros.h"

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_SPACE    8

#define MyIsAlpha(X) ( (X) >= 65 && (X) <= 90 ? LC_COLLATE : \
                       (X) >= 97 && (X) <= 122 ? LC_CTYPE : LC_ALL )

#define MyIsAscii(X) ( (X) >= 0 && (X) <= 126 ? LC_COLLATE : LC_ALL )

#define MyIsLower(X) ( (X) >= 97 && (X) <= 122 ? LC_CTYPE : LC_ALL )

#define MyIsSpace(X) ( (X) == 32 || (X) == 10 || (X) == 9 ? LC_SPACE : LC_ALL )

int main()
{
    char cadena[] = ";0 ñsáR\n(h &~?\177R\tÛ 1/";
    int i;

    for(i = 0; cadena[i]; i++)
        printf("%c, %d\n", cadena[i], isspace(cadena[i]));

    printf("\n-------\n");

    for(i = 0; cadena[i]; i++)
        printf("%c - %d\n", cadena[i], MyIsSpace(cadena[i]));


    return 0;
}
