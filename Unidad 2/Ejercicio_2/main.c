#include <stdio.h>
#include <stdlib.h>

int* obtenerDirSegunPos(int vec[], int elem);

int main()
{
    int vecInt[4] = {1,2,3,4};

    printf("Direccion de memoria del elemento 2: %p", obtenerDirSegunPos(vecInt, 2));

    return 0;
}


int* obtenerDirSegunPos(int vec[], int elem)
{
    while(*vec)
    {
        if(*vec == elem)
            return vec;
        vec++;
    }

    return NULL;
}
