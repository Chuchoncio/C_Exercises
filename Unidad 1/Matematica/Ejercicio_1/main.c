#include "main.h"

int main()
{
    int num;

    printf("Ingrese numero entero: ");
    scanf("%d", &num);

    printf("El factoria de %d es: %ld", num, factorial(num));
}
