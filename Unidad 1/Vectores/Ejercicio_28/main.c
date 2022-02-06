#include <stdio.h>
#include <stdlib.h>
#include <vectores.h>

int main()
{
    char palabra[15] = "entretenido";

    printf("El valor numerico de \"%s\" es: %d", palabra, valorNumericoCadena(palabra));

    return 0;
}
