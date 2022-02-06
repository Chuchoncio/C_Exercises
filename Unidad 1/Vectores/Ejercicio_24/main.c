#include "main.h"

int main()
{
    int vec[TAMVEC] = { 1 , 4 , 6 , 7 , 9 , 15 };
    int ce = sizeof(vec)/sizeof(int);
    int pos;

    mostrarVector(vec,ce);
    printf("\nIngrese posicion del vector a eliminar: ");
    scanf("%d", &pos);

    if(pos > ce)
        printf("Esa posicion no existe!");
    else
    {
        printf("\nLa posicion %d ha sido eliminada, la cantidad de elementos ahora es: %d", pos, ce);
        elimPosDeVector(vec, &ce, pos);
        mostrarVector(vec,ce);
    }


    return 0;
}
