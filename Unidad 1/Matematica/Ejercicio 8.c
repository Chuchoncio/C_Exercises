#include <stdio.h>

int sumasSucesivas(int n, int m);

int main()
{
    int n, m;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &n, &m);

    printf("La suma sucesiva de %d y %d es: %d", n, m, sumasSucesivas(n,m));
}

int sumasSucesivas(int n, int m)
{
    int producto = n*m;
    int sumaSuc = n;

    while(sumaSuc < producto)
        sumaSuc += n;

    return sumaSuc;
}
