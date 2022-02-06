#include "main.h"

int main()
{
    char *cadNum = "012343210",
         *cadNum2 = "42454",
         *cadNum3 = "6997568",
         *cadNum4 = "101";
    int longCad = strlen(cadNum),
        longCad2 = strlen(cadNum3);

    if(esCapicua(cadNum, longCad))
        printf("La cadena es capicua!\n");

    if(esMultiploDeCinco(cadNum, longCad))
        printf("La cadena es multiplo de 5\n");

    if(esMultiploDeSeis(cadNum2))
       printf("La cadena 2 es multiplo de 6\n");

    if(esMultiploDeOnce(cadNum3, longCad2))
       printf("La cadena 3 es multiplo de 11\n");

    if(esMayorQueCien(cadNum4))
       printf("La cadena 4 es mayor que 100\n");

    if(enRangoShort(cadNum4))
        printf("La cadena 4 entra en el rango de los short int\n");
    // Range: -32,768 to 32,767


    return 0;
}
