#include "funciones.h"

int main()
{
    FILE *pf, *pf2;
    char cad[100], *s, cadNum[10];
    int cantCifras, cantMultCinco = 0,
        cantMultSeis= 0, cantMultOnce = 0;

    pf = fopen("datosEntrada.txt", "rt");
    pf2 = fopen("datosSalida.txt", "wt");

    if(!pf || !pf2)
        exit(1);

    while(fgets(cad, 100, pf))
    {
        s = cad;
        while(*s != '\n' && *s  != '\0')
        {
            if(*s != ' ')
            {
                cantCifras = MiStrnlen(s, ' ');
                strncpy(cadNum, s, cantCifras);
                cadNum[cantCifras] = '\0';

                if(esMultiploDeCinco(cadNum, cantCifras))
                    cantMultCinco++;
                if(esMultiploDeSeis(cadNum))
                    cantMultSeis++;
                if(atoi(cadNum) % 11 == 0)
                    cantMultOnce++;
                if(esMayorQueCien(cadNum))
                    fprintf(pf2, "%s\n", cadNum);

                s += cantCifras;
            }
            else
                s++;
        }
    }

    printf("Cantidad Multiplo de 5: %d\n"
           "Cantidad Multiplo de 6: %d\n"
           "Cantidad Multiplo de 11: %d\n",
           cantMultCinco, cantMultSeis, cantMultOnce);

    fclose(pf);
    fclose(pf2);



    return 0;
}

size_t MiStrnlen(const char *s, const char c)
{
    size_t n = 0;
    while(*s && *s != c)
    {
        n++;
        s++;
    }
    return n;
}
