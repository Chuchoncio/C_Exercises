#include "main.h"

int main()
{
    int vec[TAMVEC] = { 5 , 9 , 7 , 8 , 9 };
    int ce = 5;
    int pos = 0;
    int elem = 0;

    printf("Posicion del vector: ");
    scanf("%d", &pos);
    printf("Ingrese valor a insertar: ");
    scanf("%d", &elem);

    mostrarVector(vec, TAMVEC);
    insertarEnVector(vec, elem, pos, &ce, TAMVEC);
    puts("\n");
    mostrarVector(vec, TAMVEC);

    return 0;
}
