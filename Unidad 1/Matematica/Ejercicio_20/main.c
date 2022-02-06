// Metodo de Multiplicacion rusa de dos numeros naturales

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, productoBusc = 0;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &num1, &num2);

    printf("La multiplicacion normal da: %d\n", num1*num2);

    while(num1 >= 1)
    {
        if(num1%2 != 0)
        {
            productoBusc += num2;
        }

        num1 /= 2;
        num2 *= 2;
    }

    printf("La multiplicacion rusa es: %d", productoBusc);


    return 0;
}
