// Desarrollar una funcion para determinar si un entero pertenece a la serie
// Fibonacci o no

#include "main.h"

int main()
{
    int num;

    printf("Ingrese un entero: ");
    scanf("%d", &num);

    if(esFibonacci(num))
        printf("\nEl numero %d pertenece a la serie Fibonacci", num);
    else
        printf("\nEl numero %d NO pertenece a la serie Fibonacci", num);
}
