#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool abrirArchivo(char car);

#define OPENFILE(C,type) { type *pf; pf = fopen("archivo.dat", "wb"); \
                           !pf && car == 'e' ? printf("Error al abrir el archivo!") : fclose(pf);}

// Salvo declarar variables directamente, la macro puede utilizar funciones, condicionales y bucles

int main()
{
    char car = 'e';

    OPENFILE(car, FILE);

    return 0;
}

bool abrirArchivo(char car)
{
    FILE *pf;

    pf = fopen("archivo.dat", "rb");

    if(!pf && car == 'e')
    {
        fprintf(stdout, "Error al abrir el archivo!");
        return false;
    }

    return true;
}
