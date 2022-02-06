#include "main.h"

int main(int argc, char* argv[])
{
    generarArchivo();
    agregarTexto();

//    if(argc != 2)
//    {
//        printf("Cantidad de argumentos invalida!\n");
//        exit(1);
//    }

    FILE *pf;
    char buffer[100], *puntB, *subC = "se";
    int nLinea = 1, posL, tamSubC = strlen(subC);

    pf = fopen(NOMBREARCH, "rt");

    if(!pf)
        exit(1);

    while(fgets(buffer, 100, pf))
    {
        posL = 0;
        puntB = buffer;

        while( (puntB = Mystrstr(puntB, argv[1], &posL)) != NULL )
        {
            printf("Nro Linea: %d - Pos: %d\n", nLinea, posL);
            puntB += tamSubC;
            posL += tamSubC;
        }

        nLinea++;
    }

    system("PAUSE");

    return 0;
}
