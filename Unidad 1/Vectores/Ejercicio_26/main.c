/* Desarrollar una funcion que elimine todas las apariciones de un
 *      determinado elemento de un arreglo de enteros.
 */

#include "main.h"

int main()
{
    int vec[TAMVEC] = { 4 , 4 , 6 , 7 , 4 , 9 , 4 };
    int elem = 0;
    unsigned int ce = TAMVEC-1;

    mostrarVector(vec, ce);
    puts("\n");
    puts("Ingrese elemento a eliminar (todas las apariciones): ");
    scanf("%d", &elem);

    elimTodasApari(vec, elem, &ce);

    mostrarVector(vec, TAMVEC);
    puts("\n");
    printf("Eliminada todas las apariciones de %d, quedando %d elemento/s\n", elem, ce);

    return 0;
}
