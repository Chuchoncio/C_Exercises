/* Desarrollar una función que elimine la primera aparición de un
 *      elemento determinado de un arreglo de enteros.
 */

#include "main.h"

int main()
{
    int vec[TAMVEC] = { 1 , 4 , 6 , 7 , 4 , 9 , 15 };
    int elem = 0;
    int ce = TAMVEC-1;

    mostrarVector(vec, ce);
    puts("\n");
    puts("Ingrese elemento a eliminar (primera aparicion): ");
    scanf("%d", &elem);

    elimPrimApari(vec, elem, &ce, TAMVEC);

    mostrarVector(vec, ce);
    puts("\n");
    printf("Eliminada la primera aparicion de %d\n", elem);

    return 0;
}
