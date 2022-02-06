#include "cadenas.h"

#define ES_MINUS(X)    ((X)>=97 && (X)<=122)
#define ES_MAYUS(X)    ((X)>=65 && (X)<=90)
#define A_MAYUS(X)     (ES_MINUS(X)? ((X)-32): (X))
#define A_MINUS(X)     (ES_MAYUS(X)? ((X)+32): (X))

#define TAM 40


char* mayusculasMinusculas(char* s)
{
    while(*s)
    {
        if(ES_MINUS(*s) && (*(s-1) == ' ' || *(s-1) == ','))
            *s = A_MAYUS(*s);

        if(ES_MAYUS(*s) && (*(s-1) != ' ' && *(s-1) != ','))
            *s = A_MINUS(*s);

        s++;
    }

    return s;
}

char* coma(char* s)
{
    char *cadAux = s;

    if( strchr(s, ',') == NULL)
    {
        if((cadAux = strchr(s, ' ')) == NULL)
        {
            memmove(cadAux + 1, cadAux, TAM-1 > strlen(s) ? strlen(cadAux) : strlen(cadAux)+1 );
            *cadAux = ',';
        }
    }

    /// Ahora yo tengo la coma, entonces me fijo que la que le siga sea un blanco
    /// si no lo es, corro toda la cadena hacia adelante y le colo un blanco

    return s;
}

char* no_mas_de_un_espacio(char* s)
{
    char *cadAux = s;

    while( (cadAux = strstr(cadAux, "  ")) != NULL )
        strcpy(cadAux, cadAux + 1);

    return s;
}

char* sin_espacios_inicio_fin(char* s)
{
    if(*s == ' '){
        strcpy(s, s+1);
    }

    if(*(s + strlen(s)) == ' ')
        *(s + strlen(s)) = '\0';

    return s;
}

int cantidad_apariciones(const char* s, char c)
{
    int cantidad = 0;
    while(*s)
    {
        if(*s == c)
            cantidad++;

        s++;
    }
    cantidad++;

    return cantidad;
}
