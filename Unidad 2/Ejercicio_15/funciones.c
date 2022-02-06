#include "main.h"

/* Localiza la primera aparición en la cadena apuntada por s1 de la secuencia de
 *   caracteres (excluyendo el carácter nulo) en la cadena apuntada por s2.
 */
char* Mystrstr(const char *s1, const char *s2, int* pos)
{
    if(s2 == NULL || *s2 == '\0')
        return (char*)s1;

    char *cad1, *cad2;
    int offset=0;

    cad1 = (char*)s1;
    cad2 = (char*)s2;

    while(*cad2 && *cad1)
    {
        if(*cad1 == *cad2)
        {
            cad2++;
            offset++;
        }
        else
        {
            offset = 0;
            cad2 = (char*)s2;
        }

        cad1++;
        (*pos)++;
    }

    if(offset)
    {
        (*pos) -= offset;
        return (char*)cad1 - offset;
    }
    else
    {
        (*pos) = 0;
        return NULL;
    }
}

void generarArchivo()
{
    FILE *pf;

    pf = fopen(NOMBREARCH, "wt");

    if(!pf)
        exit(1);

    fprintf(pf, "La wea similarity --- condensador\n"
                "    Hacia donde se dirige la humanidad?\n"
                "Realmente hemos evolucionado amigos!?\n"
                "se, calculo que se\n"
                "-- usted pergola se la vive en el reino dol jogete\n"
                "CALAMARINO, MI RIVAL DE TODA LA VIDA\n");

    fclose(pf);
}

void agregarTexto()
{
    FILE *pf;

    pf = fopen(NOMBREARCH, "a+t");

    if(!pf)
        exit(1);

    fprintf(pf, "QUISEAWEA ESA WEAAAAA\n"
                " Segurisimo ese lugar, eh!\n"
                " se anda diciendo por ahi...\n"
                "se tu mismo o te cojen amiguito!");
    fclose(pf);

}
