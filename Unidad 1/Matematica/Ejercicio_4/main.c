/* Desarrollar una funcion para calcular la raíz cuadrada de X
 * con una tolerancia TOL
 */

#include "main.h"

int main()
{
    int a;
    float tol;

    printf("Ingrese numero positivo y valor TOL: ");
    scanf("%d %f", &a, &tol);

    printf("La raiz cuadrada de %d es: %.2f", a, calcularRaizCuadrada(a, tol));
}
