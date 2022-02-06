#include <stdio.h>

int verificarNPrimo(int num);

int main()
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if(verificarNPrimo(num))
        printf("El numero %d es primo",num);
    else
        printf("El numero %d es compuesto",num);

    return 0;
}

int verificarNPrimo(int num)
{
    if(num == 1)
        return 0;

    int i, cont=0;

    for(i = num; i > 1; i--)
    {
        if(num%i==0)
            cont++;
    }

    return cont == 1? 1 : 0;
}
