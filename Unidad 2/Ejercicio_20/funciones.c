#include "main.h"

int factorialRecur(int n)
{
    if(n == 1)
        return n;

    return n*factorialRecur(n-1);
}

void mostrarVecRecur(char* cad)
{
    if(!*cad)
        return ;

    printf("%c", *cad);
    mostrarVecRecur(++cad);
}

void mostrarVecInvRecur(char* cad)
{
    if(!*cad)
        return ;

    mostrarVecInvRecur(++cad);
    printf("%c", *(--cad));
}

int sumaYMostrarVecRecur(char* cad)
{
    if(!*cad)
        return 0;

    static int suma = 0;

    if(isdigit(*cad))
        suma += atoi(cad);

    sumaYMostrarVecRecur(++cad);
    printf("%c", *(--cad));

    return suma;
}

int sumaYMostrarVecIntRecur(int* vec)
{
    if(!*vec)
        return 0;

    static int suma = 0;

    suma += *vec;
    sumaYMostrarVecIntRecur(++vec);
    printf("%d", *(--vec));

    return suma;
}

int sumaYMostrarVecIntParesRecur(int* vec)
{
    if(!*vec)
        return 0;

    static int suma = 0;

    if(*vec % 2 == 0)
        suma += *vec;

    sumaYMostrarVecIntParesRecur(++vec);
    printf("%d", *(--vec));

    return suma;
}

int MyIntLen(int* vec)
{
    int cantElem = 0;

    while(*vec)
    {
        cantElem++;
        vec++;
    }

    return cantElem;
}

int sumaYMostrarVecIntPosParRecur(int* vec)
{
    if(!*vec)
        return 0;

    static int suma = 0;
    int longCad = MyIntLen(vec);

    if(longCad % 2 == 0)
        suma += *vec;

    sumaYMostrarVecIntPosParRecur(++vec);
    printf("%d", *(--vec));

    return suma;
}

char *MiStrchrRec(char *s, int c)
{
    static char* r;

    if(!*s)
        return NULL;

    MiStrchrRec(++s, c);

    if(*s == c)
        r = s;

    return r;
}

char *MiStrrchrRec(char *s, int c)
{
    static char* r;

    if(!*s)
        return NULL;
    else if(*s == c)
        return r = s;

    MiStrrchrRec(++s, c);


    return r;
}

int MiStrlenRec(const char *s)
{
    if(!*s)
        return 0;

    static int n = 0;

    n++;
    MiStrlenRec(++s);

    return n;
}
