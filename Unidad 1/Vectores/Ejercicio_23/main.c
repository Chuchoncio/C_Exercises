#include "main.h"

/** Desarrollar una función que inserte un elemento en un arreglo
 **     de enteros, ordenado en forma ascendente, de forma de no
 **     alterar el orden.
 **/
int main()
{
    int vec[TAMVEC] = { 1 , 4 , 6 , 7 , 9 , 15 };
    int ce = 5;
    int elem = 0;

    printf("Ingrese valor a insertar: ");
    scanf("%d", &elem);

    mostrarVector(vec, TAMVEC);
    insertarEnVectorYOrdenarAsc(vec, &elem, &ce, TAMVEC);
    puts("\n\nVector luego de insertar y ordenar\n");
    mostrarVector(vec, TAMVEC);
    puts("\n");

    return 0;
}
