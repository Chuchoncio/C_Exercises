#include "main.h"

void archNoventaAzar(char* pathArch)
{
    FILE *pf;
    int n, m, cotaInf, cotaSup;

    pf = fopen(pathArch, "wb");

    if(!pf)
    {
        printf("Error en el archivo");
        exit(1);
    }

    cotaInf = 100;
    cotaSup = 999;

    m = 0;

    while(m < 90)
    {
        n = cotaInf + rand() % (cotaSup+1 - cotaInf);
        fwrite(&n, sizeof(n), 1, pf);
        m++;
    }

    fclose(pf);
}

void dividirEnTresBin(char* pathBinOrg, char* pathBin1,
                      char* pathBin2, char* pathBin3)
{
    FILE *pfBinOg, *pfBin1, *pfBin2, *pfBin3;
    int n, limit = 0;

    pfBinOg = fopen(pathBinOrg, "rb");
    pfBin1 = fopen(pathBin1, "wb");
    pfBin2 = fopen(pathBin2, "wb");
    pfBin3 = fopen(pathBin3, "wb");

    if(!pfBinOg || !pfBin1 || !pfBin2 || !pfBin3)
    {
        printf("Error en algun archivo");
        exit(1);
    }

    while(limit < 90 && !feof(pfBinOg))
    {
        fread(&n, sizeof(n), 1, pfBinOg);

        if(limit >= 0 && limit < TAMVEC)
            fwrite(&n, sizeof(n), 1, pfBin1);
        else if(limit >= TAMVEC && limit < 60)
            fwrite(&n, sizeof(n), 1, pfBin2);
        else if(limit > 60 && limit <= 90)
            fwrite(&n, sizeof(n), 1, pfBin3);

        limit++;
    }

    fclose(pfBinOg);
    fclose(pfBin1);
    fclose(pfBin2);
    fclose(pfBin3);
}

void convertirBinATxt(char* pathBin1, char* pathBin2, char* pathBin3,
                      char* pathText1, char* pathText2, char* pathText3)
{
    FILE *pfBin1, *pfBin2, *pfBin3,
         *pfText1, *pfText2, *pfText3;
    int n, limit;

    pfBin1 = fopen(pathBin1, "rb");
    pfBin2 = fopen(pathBin2, "rb");
    pfBin3 = fopen(pathBin3, "rb");

    pfText1 = fopen(pathText1, "wt");
    pfText2 = fopen(pathText2, "wt");
    pfText3 = fopen(pathText3, "wt");

    if(!pfBin1 || !pfBin2 || !pfBin3 ||
            !pfText1 || !pfText2 || !pfText3)
    {
        printf("Error en algun archivo");
        exit(1);
    }

    for(limit = 0; limit < 90; limit++)
    {
        if(limit >= 0 && limit < TAMVEC)
        {
            fread(&n, sizeof(n), 1, pfBin1);
            fprintf(pfText1, "%d ", n);
        }
        else if(limit >= TAMVEC && limit < 60)
        {
            fread(&n, sizeof(n), 1, pfBin2);
            fprintf(pfText2, "%d ", n);
        }
        else if(limit >= 60 && limit < 90)
        {
            fread(&n, sizeof(n), 1, pfBin3);
            fprintf(pfText3, "%d ", n);
        }
    }

    fclose(pfBin1);
    fclose(pfBin2);
    fclose(pfBin3);
    fclose(pfText1);
    fclose(pfText2);
    fclose(pfText3);
}

void transformarArchs(char* pathText1, char* pathText2, char* pathText3,
                      char* pathTextConv1, char* pathTextConv2, char* pathTextConv3)
{
    FILE *pfText1, *pfText2, *pfText3,
         *pfTextCon1, *pfTextCon2, *pfTextCon3;
    int num, limit;
    char cad[4];

    pfText1 = fopen(pathText1, "rt");
    pfText2 = fopen(pathText2, "rt");
    pfText3 = fopen(pathText3, "rt");

    pfTextCon1 = fopen(pathTextConv1, "wt");
    pfTextCon2 = fopen(pathTextConv2, "wt");
    pfTextCon3 = fopen(pathTextConv3, "wt");

    if(!pfText1 || !pfText2 || !pfText3 ||
            !pfTextCon1 || !pfTextCon2 || !pfTextCon3)
    {
        printf("Error en algun archivo");
        exit(1);
    }

    for(limit = 0; limit < 90; limit++)
    {
        if(limit >= 0 && limit < TAMVEC)
        {
            fscanf(pfText1, "%d", &num);
            transformarNums(num, cad, "ABCDEFGHIJ");
            fprintf(pfTextCon1, "%s ", cad);
        }
        else if(limit >= TAMVEC && limit < 60)
        {
            fscanf(pfText2, "%d", &num);
            transformarNums(num, cad, "KMNLOPQRST");
            fprintf(pfTextCon2, "%s ", cad);
        }
        else if(limit >= 60 && limit < 90)
        {
            fscanf(pfText3, "%d", &num);
            transformarNums(num, cad, "UVWXYZABCD");
            fprintf(pfTextCon3, "%s ", cad);
        }
    }

    fclose(pfText1);
    fclose(pfText2);
    fclose(pfText3);
    fclose(pfTextCon1);
    fclose(pfTextCon2);
    fclose(pfTextCon3);
}

void transformarNums(int num, char* cad, char* vecConv)
{
    int a, b, c;

    a = num / 100;
    b = (num % 100) / 10;
    c = num % 10;

    *cad = *(vecConv+a);
    *(cad+1) = *(vecConv+b);
    *(cad+2) = *(vecConv+c);
    *(cad+3) = '\0';
}

void ordenarArchsText(char* pathTextConv1, char* pathTextConv2, char* pathTextConv3,
                      char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3)
{
    FILE *pfTextCon1, *pfTextCon2, *pfTextCon3,
         *pfTextOrd1, *pfTextOrd2, *pfTextOrd3;
    int limit;
    char *bufferT1[TAMVEC], *bufferT2[TAMVEC], *bufferT3[TAMVEC];

    pfTextCon1 = fopen(pathTextConv1, "rt");
    pfTextCon2 = fopen(pathTextConv2, "rt");
    pfTextCon3 = fopen(pathTextConv3, "rt");

    pfTextOrd1 = fopen(pathTextOrd1, "wt");
    pfTextOrd2 = fopen(pathTextOrd2, "wt");
    pfTextOrd3 = fopen(pathTextOrd3, "wt");

    if(!pfTextCon1 || !pfTextCon2 || !pfTextCon3 ||
            !pfTextOrd1 || !pfTextOrd2 || !pfTextOrd3)
    {
        printf("Error en algun archivo");
        exit(1);
    }

    for(limit = 0; limit < TAMVEC; limit++)
    {
        bufferT1[limit] = (char*)malloc(4);
        bufferT2[limit] = (char*)malloc(4);
        bufferT3[limit] = (char*)malloc(4);
        fgets(bufferT1[limit], 5, pfTextCon1);
        fgets(bufferT2[limit], 5, pfTextCon2);
        fgets(bufferT3[limit], 5, pfTextCon3);
    }

    quicksort(bufferT1, 0, TAMVEC-1, 5*sizeof(char));
    quicksort(bufferT2, 0, TAMVEC-1, 5*sizeof(char));
    quicksort(bufferT3, 0, TAMVEC-1, 5*sizeof(char));

    for(limit = 0 ; limit < TAMVEC ; limit++)
    {
        fprintf(pfTextOrd1, "%s", bufferT1[limit]);
        fprintf(pfTextOrd2, "%s", bufferT2[limit]);
        fprintf(pfTextOrd3, "%s", bufferT3[limit]);
    }

    fclose(pfTextCon1);
    fclose(pfTextCon2);
    fclose(pfTextCon3);
    fclose(pfTextOrd1);
    fclose(pfTextOrd2);
    fclose(pfTextOrd3);
}

void ordenarVector(char* cad[], int cantElem, int tamElem,
                   int cmp(const void*, const void*))
{
    int i, k;
    char cadAux[tamElem];

    // Desde el segundo elemento
    for (i = 1; i < cantElem; i++)
    {
        strcpy(cadAux, cad[i]);
        k = i-1;
        // Para k=-1, se ha alcanzado el extremo izquierdo.
        while (k >= 0 && (cmp(cadAux, cad[k]) == -1))
        {
            // hacer hueco para insertar
            strcpy(cad[k+1], cad[k]);
            k--;
        }
        // insertar x en su lugar
        strcpy(cad[k+1], cadAux);
    }
}

void quicksort(char* cad[], int inf, int sup, int cantElem)
{
    int izq = 0, der = 0;
    char mitad[cantElem], aux[cantElem];

    izq = inf;
    der = sup;
    strcpy(mitad, cad[(izq+der)/2]);

    do
    {
        while ((strcmp(cad[izq], mitad) == -1) && izq < sup)
            izq++;
        while ((strcmp(mitad, cad[der]) == -1) && der > inf)
            der--;
        if (izq <= der)
        {
            strcpy(aux, cad[izq]);
            strcpy(cad[izq], cad[der]);
            strcpy(cad[der], aux);

            izq++;
            der--;
        }
    }
    while (izq <= der);

    if (inf < der)
        quicksort(cad, inf, der, cantElem);
    if (izq < sup)
        quicksort(cad, izq, sup, cantElem);
}

int MyStrCmp(const void *cad1, const void *cad2)
{
    char* c1 = (char*)cad1;
    char* c2 = (char*)cad2;

    return strcmp(c1, c2);
}

void generarArchOrdFinal(char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3,
                         char* pathArchFinal)
{
    FILE *pfTextOrd1, *pfTextOrd2, *pfTextOrd3,
         *pfArchFinal;
    int limit;
    char bufferT1[4], bufferT2[4], bufferT3[4];

    pfTextOrd1 = fopen(pathTextOrd1, "rt");
    pfTextOrd2 = fopen(pathTextOrd2, "rt");
    pfTextOrd3 = fopen(pathTextOrd3, "rt");
    pfArchFinal = fopen(pathArchFinal, "wt");

    if(!pfTextOrd1 || !pfTextOrd2 || !pfTextOrd3 ||
            !pfArchFinal)
    {
        printf("Error en algun archivo");
        exit(1);
    }

    for(limit = 0; limit < 90; limit++)
    {
        if(limit >= 0 && limit < 30)
        {
            fscanf(pfTextOrd1, "%s", bufferT1);
            //fgets(bufferT1, 8, pfTextOrd1);
            fprintf(pfArchFinal,"%s ", bufferT1);
        }
        else if(limit >= 30 && limit < 60)
        {
            fscanf(pfTextOrd2, "%s", bufferT2);
            //fgets(bufferT1, 8, pfTextOrd1);
            fprintf(pfArchFinal,"%s ", bufferT2);
        }
        else
        {
            fscanf(pfTextOrd3, "%s", bufferT3);
            //fgets(bufferT1, 8, pfTextOrd1);
            fprintf(pfArchFinal,"%s ", bufferT3);
        }
    }

    fclose(pfTextOrd1);
    fclose(pfTextOrd2);
    fclose(pfTextOrd3);
    fclose(pfArchFinal);
}

void borrarArchivosIntermedios(char* pathBin1, char* pathBin2, char* pathBin3,
                               char* pathText1, char* pathText2, char* pathText3,
                               char* pathTextConv1, char* pathTextConv2, char* pathTextConv3,
                               char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3)
{
    remove(pathBin1);
    remove(pathBin2);
    remove(pathBin3);
    remove(pathText1);
    remove(pathText2);
    remove(pathText3);
    remove(pathTextConv1);
    remove(pathTextConv2);
    remove(pathTextConv3);
    remove(pathTextOrd1);
    remove(pathTextOrd2);
    remove(pathTextOrd3);
}

void mostrarBinario(char* pathArch)
{
    FILE *pf;
    int n, limit = 89;

    pf = fopen(pathArch, "rb");

    if(!pf)
    {
        printf("Error en el archivo");
        exit(1);
    }

    while(!feof(pf) && limit >= 0)
    {
        fread(&n, sizeof(n), 1, pf);
        printf("%d ", n);
        limit--;
    }

    fclose(pf);
}
