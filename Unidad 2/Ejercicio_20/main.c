#include "main.h"

int main()
{
    int vec[7] = {1,2,3, 4, 5, 6};
    char cad[] = "Hola amigos";
    char c = 'a';

    printf("!%d = %d\n", 5, factorialRecur(5));
    mostrarVecRecur("cuchame");
    puts("\n");
    mostrarVecInvRecur("australopitecus");
    puts("\n");
    printf("\n%d", sumaYMostrarVecRecur("cu1cha4me6"));
    puts("\n");
    printf("\n%d", sumaYMostrarVecIntRecur(vec));
    puts("\n");    printf("\n%d", sumaYMostrarVecIntParesRecur(vec));
    puts("\n");
    printf("\n%d", sumaYMostrarVecIntPosParRecur(vec));
    puts("\n");
    printf("%d", MiStrlenRec("cuchame una co"));
    puts("\n");
    printf("--> pos = %s", MiStrrchrRec(cad, c));


    return 0;
}
