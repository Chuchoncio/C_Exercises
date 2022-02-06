#include "main.h"

int main(int argc, char* argv[])
{
    char pathBinOrg[TAMPATH] = "archalea.bin",
         pathBin1[TAMPATH] = "archal1.bin",
         pathBin2[TAMPATH] = "archal2.bin",
         pathBin3[TAMPATH] = "archal3.bin",
         pathText1[TAMPATH] = "archl1.txt",
         pathText2[TAMPATH] = "archl2.txt",
         pathText3[TAMPATH] = "archl3.txt",
         pathTextConv1[TAMPATH] = "archtex1.txt",
         pathTextConv2[TAMPATH] = "archtex2.txt",
         pathTextConv3[TAMPATH] = "archtex3.txt",
         pathTextOrd1[TAMPATH] = "archord1.txt",
         pathTextOrd2[TAMPATH] = "archord2.txt",
         pathTextOrd3[TAMPATH] = "archord3.txt",
         pathArchFinal[TAMPATH] = "archord.txt",
         opc;


    archNoventaAzar(pathBinOrg);
    mostrarBinario(pathBinOrg);
    dividirEnTresBin(pathBinOrg, pathBin1, pathBin2, pathBin3);
    convertirBinATxt(pathBin1, pathBin2, pathBin3, pathText1, pathText2, pathText3);
    transformarArchs(pathText1, pathText2, pathText3, pathTextConv1, pathTextConv2, pathTextConv3);
    ordenarArchsText(pathTextConv1, pathTextConv2, pathTextConv3, pathTextOrd1, pathTextOrd2, pathTextOrd3);
    generarArchOrdFinal(pathTextOrd1, pathTextOrd2, pathTextOrd3, pathArchFinal);

    puts("\nDesea eliminar los archivos intermedios? (SI - s | NO - n)");
    scanf("%c", &opc);
    if(opc == 's')
        borrarArchivosIntermedios(pathBin1, pathBin2, pathBin3, pathText1, pathText2, pathText3, pathTextConv1,
                                    pathTextConv2, pathTextConv3, pathTextOrd1, pathTextOrd2, pathTextOrd3);

    return 0;
}
