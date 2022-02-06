#include <stdio.h>

int sumaParesN(int n);

int main()
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d",&n);

    printf("La suma de los primeros %d naturales pares es: %d",n,sumaParesN(n));

    return 0;
}

int sumaParesN(int n)
{
    int i;
    int sumaNP = 0;

    for(i = n; i > 0; i--)
    {
        if(i%2==0)
            sumaNP += i;
    }

    return sumaNP;
}
