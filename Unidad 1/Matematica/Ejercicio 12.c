#include <stdio.h>

int sumaParesMenosN(int n);

int main()
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d",&n);

    printf("La suma de los primeros %d naturales pares es: %d",n,sumaParesMenosN(n));

    return 0;
}

int sumaParesMenosN(int n)
{
    int i;
    int sumaNP = 0;

    for(i = n-1; i > 0; i--)
    {
        if(i%2==0)
            sumaNP += i;
    }

    return sumaNP;
}
