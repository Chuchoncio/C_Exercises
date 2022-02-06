#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMPATH 30
#define TAMVEC 30

void mostrarBinario(char* pathArch);
void archNoventaAzar(char* pathArch);
void dividirEnTresBin(char* pathBinOrg, char* pathBin1,
                      char* pathBin2, char* pathBin3);
void convertirBinATxt(char* pathBin1, char* pathBin2, char* pathBin3,
                      char* pathText1, char* pathText2, char* pathText3);
void transformarArchs(char* pathText1, char* pathText2, char* pathText3,
                      char* pathTextConv1, char* pathTextConv2, char* pathTextConv3);
void transformarNums(int num, char* cad, char* vecConv);
void ordenarArchsText(char* pathTextConv1, char* pathTextConv2, char* pathTextConv3,
                      char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3);
int MyStrCmp(const void *cad1, const void *cad2);
void ordenarVector(char* buffer[], int cantElem, int tamElem,
                   int cmp(const void*, const void*));
void generarArchOrdFinal(char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3,
                         char* pathArchFinal);
void borrarArchivosIntermedios(char* pathBin1, char* pathBin2, char* pathBin3,
                               char* pathText1, char* pathText2, char* pathText3,
                               char* pathTextConv1, char* pathTextConv2, char* pathTextConv3,
                               char* pathTextOrd1, char* pathTextOrd2, char* pathTextOrd3);
void quicksort(char* cad[], int inf, int sup, int cantElem);

#endif // MAIN_H_INCLUDED
