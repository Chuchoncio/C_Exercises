#include <stdio.h>
#include <math.h>
#include "matematica.h"

int main()
{
    double num;
    double TOL;

    printf("Ingrese X y TOL: ");
    scanf("%lf %lf", &num, &TOL);

    printf("El seno de %.2lf es: %.8lf",num,obtenerSeno(num, TOL));

    return 0;
}
