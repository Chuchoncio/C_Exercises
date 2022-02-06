#include <stdio.h>

char* clasificacionNaturales(int num);

int main()
{
    int num;

    printf("Ingrese numero: ");
    scanf("%d", &num);

    printf("Su numero %d es: %s",num,clasificacionNaturales(num));

    return 0;
}

char* clasificacionNaturales(int num)
{
    int i;
    int divPos = 0;

    for(i = num-1; i > 0; i--)
    {
        if(num%i == 0)
            divPos += i;
    }

    if(divPos > num)
        return "ABUNDANTE";
    else if(divPos == num)
        return "PERFECTO";
    else
        return "DEFICIENTE";

}
