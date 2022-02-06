#include <stdio.h>

float cocienteYResto(int a, int b);

int main()
{
    int a, b;
    float res;

    do
    {
        printf("Ingrese dos numeros: ");
        scanf("%d %d", &a, &b);
    }while(b == 0);

    res = cocienteYResto(a,b);

    printf("El cociente (mas su resto) entre %d y %d es: %.4f",a,b,res);

    return 0;
}

float cocienteYResto(int a, int b)
{
    int cociente = a/b;
    float resto = a%b * 0.1;
    float numTotal = cociente + resto;

    return numTotal;
}
