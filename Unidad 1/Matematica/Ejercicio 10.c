#include <stdio.h>

int sumaPrimerosN(int n);

int main()
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d",&n);

    printf("La suma de los primeros %d naturales es: %d",n,sumaPrimerosN(n));

    return 0;
}

int sumaPrimerosN(int n)
{
    int i;
    int sumaN = 0;

    for(i = n; i > 0; i--)
    {
        sumaN += i;
    }

    return sumaN;
}
