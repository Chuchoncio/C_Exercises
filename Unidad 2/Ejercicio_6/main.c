#include <stdio.h>
#include <stdlib.h>

#define ENTEROMASCERCANO(X) ( ((X)-(int)(X)) > 0.5 ? (int)((X)+1) :  (int)(X) )
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y) )
#define MAX(X,Y) ( (X) > (Y) ? (X) : (Y) )
#define SWAP(X,Y,type) {type (Z) = (X); \
                        (X) = (Y); \
                        (Y) = (Z); }

// Como una macros se expande cuando se ejecuta el codigo, el type asegura que
//  pueda pasar el tipo de variable que quiero declarar (aunque podria llamarse
//  de otra manera en vez de type)


int main()
{
    float num = 5.47;
    int n1 = 1, n2 = 5;


    printf("El entero mas cercano a %.2f es %d\n", num, ENTEROMASCERCANO(num));
    printf("El menor entre %d y %d es %d\n", n1, n2, MIN(n1, n2));
    printf("El mayor entre %d y %d es %d\n", n1, n2, MAX(n1, n2));

    SWAP(n1,n2,int);

    printf("Valor actual n1: %d, n2: %d\n", n1, n2);

    return 0;
}
