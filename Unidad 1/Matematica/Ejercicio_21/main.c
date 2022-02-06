#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numReal;
    int parteEntera;

    printf("Digite numero real: ");
    scanf("%f", &numReal);

    parteEntera = (int)numReal;

    printf("Numero real: %.2f\n", numReal);
    printf("Parte entera: %d\n", parteEntera);



    return 0;
}
