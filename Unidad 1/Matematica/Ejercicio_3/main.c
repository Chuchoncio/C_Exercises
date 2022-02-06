// Desarrollar una funcion para calcular el e^x, dados X y TOL

#include "main.h"

int main()
{
    int x;
    float tol;

    printf("Ingrese numero entero y TOL: ");
    scanf("%d %f", &x, &tol);

    printf("La funcion e^x da como resultado: %.2f", calcularE(x, tol));

}
