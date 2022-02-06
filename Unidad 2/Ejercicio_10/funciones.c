#include "main.h"

bool esCapicua(char *cad, int tamCad)
{
    char *cadIni = cad,
         *cadFin = cad + (tamCad-1);

    while( cadIni != cadFin && (*cadIni && *cadFin) )
    {
        if(*cadIni != *cadFin)
            return false;

        cadIni++;
        cadFin--;
    }

    return true;
}

bool esMultiploDeCinco(char *cad, int tamCad)
{
    char *cadFin = cad + (tamCad-1);

    if(*cad == '0')
        return false;

    return *cadFin == '5' || *cadFin == '0';
}

bool esMultiploDeSeis(char *cad)
{
    int sumaDig = 0, ultDig;

    while(*cad)
    {
        sumaDig += *cad - '0';
        cad++;
    }

    ultDig = atoi(cad-1);

    return sumaDig % 3 == 0 && ultDig % 2 == 0;
}

bool esMultiploDeOnce(char *cad, int tamCad)
{
    int sumaPosPar = 0, sumaPosImpar = 0, i = 0;

    while(*cad != '\0')
    {
        if(i % 2 == 0)
            sumaPosPar += *cad - '0';
        else
            sumaPosImpar += *cad - '0';

        cad++;
        i++;
    }

    return sumaPosPar % 11 == 0 && sumaPosImpar % 11 == 0;
}

bool esMayorQueCien(char *cad)
{
    return atoi(cad) > 100;
}

bool enRangoShort(char *cad)
{
    return atoi(cad) > -32768 && atoi(cad) < 32767;
}
