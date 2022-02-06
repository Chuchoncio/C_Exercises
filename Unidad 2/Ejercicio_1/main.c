#include "main.h"

int main()
{
    int opc, cantMax = 0, cantElemVec;
    float vecReales[TAMVEC];

    printf("Ingrese cantidad maxima de elementos del vector: ");
    scanf("%d", &cantMax);

    cantElemVec = ingresarVector(vecReales, cantMax);
    system("CLS");

    do
    {
        printf("Vector: ");
        mostrarVector(vecReales, cantElemVec);
        menuOpciones();
        scanf("%d", &opc);
        system("CLS");

        switch(opc)
        {
        case 1:
            printf("\nEl minimo del array es: %.2f\n", buscarMinimo(vecReales, cantElemVec));
            break;

        case 2:
            printf("\nEl promedio de las posiciones pares del vector es: %.2f\n", calcularPromedioPosPar(vecReales, cantElemVec));
            break;

        case 3:
            printf("\nVector en orden inverso: \n");
            mostrarOrdenInverso(vecReales, cantElemVec);
            break;
        }

        printf("\n");
        system("PAUSE");
        system("CLS");

        fflush(stdin);
    }
    while(opc != 4);

    grabarVecEnArch(vecReales, cantElemVec);
    return 0;
}

void menuOpciones()
{
    printf("\n1.Buscar minimo elemento \n"
           "2.Calcular el promedio de los valores de las posiciones pares\n"
           "3.Mostrar vector en orden inverso\n"
           "4.Salir\n");
    printf("Opcion: ");
}
