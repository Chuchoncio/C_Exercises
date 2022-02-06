#include "main.h"

int MyStrCLen(char* cad, char c)
{
    // TODO que cuente cantidad de letras hasta que llegue a caracter c
    //  Si no encuentra el caracter pedido, devuelve la longitud total
    //  de la cadena.

    char *str = cad;
    int cantC = 0;

    while(*str && *str != ' ')
    {
        cantC++;
        str++;
    }

    return cantC;
}

// Metodo alternativo para recorrer la palabra de una linea de texto
//char* MyStrCCpy(char *s1, const char *s2, char c)
//{
//    // TODO: el contenido de s2 lo copia en s1 hasta que llegue
//    //          al caracter c
//}

int main()
{
    char subCad[5], *pSubCad, buffer[100], *pBuffer, *pFinPalabra;
    FILE *pf;
    int cantPalUnaLetra = 0, cantPalCantPar = 0,
        cantPalComConN = 0, cantPalComConCad = 0,
        cantPalTresVocal = 0, cantPalCyTVocal = 0,
        cantPalConDigit = 0, cantPalSoloDigit = 0,
        cantPalPalindromo = 0;
    int paridad = 0, tamSubCad, tresVocales = 0, comConVocal = 0,
        cantDigitos = 0, cantLetras = 0, esPalindromo;

    pf = fopen(NOMBREARCH, "rt");

    if(!pf)
        exit(1);

    puts("Ingrese subcadena: ");
    gets(subCad);

    tamSubCad = strlen(subCad);

    // Chequear esta monstruosidad

    while(fgets(buffer, 100, pf))
    {
        pBuffer = buffer;
        pSubCad = subCad;

        cantLetras = MyStrCLen(pBuffer, ' ');
        pFinPalabra = (strchr(pBuffer, 32) - 1); // 32 --> ' '

        while(*pBuffer != ' ')
        {
            if(*(pBuffer-1) == ' ' && *(pBuffer+1) == ' ')
                cantPalUnaLetra++;

            if(*pFinPalabra == *pBuffer)
            {
                pFinPalabra--;
                esPalindromo = 1;
            }
            else
                esPalindromo = 0;

            if(*pBuffer == 'n' && *(pBuffer-1) == ' ')
                cantPalComConN++;

            if(*pBuffer == *pSubCad)
                pSubCad++;
            else if(*pSubCad == '\0')
                cantPalComConCad++;

            if(ESVOCAL(*pBuffer))
                tresVocales++;

            if(*(pBuffer-1) == ' ' && ESVOCAL(*pBuffer))
                comConVocal = 1;

            if(ESDIGITO(*pBuffer))
                cantDigitos++;

            paridad++;
            pBuffer++;
        }

        if(paridad % 2 == 0)
            cantPalCantPar++;

        if(tresVocales > 3)
            cantPalTresVocal++;

        if(comConVocal && ESVOCAL(*(pBuffer-1)))
            cantPalCyTVocal++;

        if(cantLetras == cantDigitos)
            cantPalSoloDigit++;
        else if(cantDigitos > 0)
            cantPalConDigit++;

        if(esPalindromo)
            cantPalPalindromo++;

        cantLetras = 0;
        tresVocales = 0;
        paridad = 0;

        pSubCad -= tamSubCad;
        pBuffer++;
    }

    printf("Formadas por una sola letra: %d\n"
           "Formadas por una cantidad par de letras: %d\n"
           "Comienzan con \'n\': %d\n"
           "Comienzan con %s: %d\n"
           "Tienen mas de tres vocales: %d\n"
           "Comienzan y terminan con vocales: %d\n"
           "Contienen digitos: %d\n"
           "Solo estan formadas por digitos: %d\n"
           "Son palindromos: %d",
           cantPalUnaLetra, cantPalCantPar, cantPalComConN,
           subCad, cantPalComConCad, cantPalTresVocal,
           cantPalCyTVocal, cantPalConDigit, cantPalSoloDigit,
           cantPalPalindromo);


    fclose(pf);

    return 0;
}
