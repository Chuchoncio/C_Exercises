#include "funciones.h"

void mostrarVector(int* v, int ce)
{
    for(int i = 0 ; i < ce ; i++)
    {
        printf("[%d]", *v);
        v++;
    }
}

void elimPosDeVector(int* vec, int* ce, int pos)
{
    int* ptrVec = vec+(pos-1);
    int huboElim = 0;

    if(pos > *ce)
        printf("\nNo existe esa posicion, dude!");
    else
    {
        while(*ptrVec)
        {
            *ptrVec = *(ptrVec+1);
            ptrVec++;
        }
        huboElim = 1;
    }

    if(huboElim)
        *ce -= 1;
}
