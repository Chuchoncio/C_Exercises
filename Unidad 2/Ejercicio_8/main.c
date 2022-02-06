#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CONDICION(X) ( (X) != '.' && (X) != '\0')

int main()
{
    char *cadena = "Cuchame una cosa cosa cuchame cosa cosa.";
    char primeraPalabra[10];
    int cantPalabras = 0, longPal = 0, longPalMasLarga = 0, cantPrimPal = 0, i = 0;

    while(*cadena != ' ')
    {
        primeraPalabra[i] = *cadena;
        longPalMasLarga++;
        cadena++;
        i++;
    }

    cantPalabras++;
    primeraPalabra[i] = '\0';
    i = 0;
    cadena++;

    while(CONDICION(*cadena))
    {
        while(*cadena != ' ' && CONDICION(*cadena))
        {
            if(tolower(*cadena) == tolower(primeraPalabra[i]))
                i++;
            else if(primeraPalabra[i+1] == '\0' || primeraPalabra[i+1] == ' ')
            {
                cantPrimPal++;
                i = 0;
            }
            else
                i = 0;

            longPal++;
            cadena++;
        }

        cantPalabras++;

        if(longPal > longPalMasLarga)
            longPalMasLarga = longPal;

        longPal = 0;
        cadena++;
    }

    printf("a) Primera palabra: %s , se repite: %d veces\n", primeraPalabra, cantPrimPal);
    printf("b) Cantidad de palabras en el texto: %d\n", cantPalabras);
    printf("c) Longitud palabra mas larga: %d\n", longPalMasLarga);


    return 0;
}
