#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char numPtrINT[5] = "1234";
    printf("La cadena \"%s\" en INT es: %d\n", numPtrINT, atoi(numPtrINT));

    char numPtrLONG[11] = "1234567890";
    printf("La cadena \"%s\" en LONG es: %ld\n", numPtrLONG, atol(numPtrLONG));

    int num = 78965423;
    char numPtrINT2[9];
    printf("El numero %d en cadena es: \"%s\"\n", num, itoa(num, numPtrINT2, 10));

    char numPtrFLOAT[6] = "11.23";
    printf("La cadena \"%s\" en FLOAT es: %.2f\n", numPtrFLOAT, atof(numPtrFLOAT));


    return 0;
}
