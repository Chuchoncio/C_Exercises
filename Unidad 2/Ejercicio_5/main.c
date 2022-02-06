#include <stdio.h>
#include <stdlib.h>

int main()
{
    ////////////////////////////// - SSCANF - //////////////////////////////
//    char nombre[20] = "", entrada[81]="";
//    unsigned int edad = 0;
//    int cantEntradas;
//    float peso = 0;
//
//    printf("Escriba su nombre, edad y peso, separados por un espacio:\n");
//    gets(entrada);
//    cantEntradas = sscanf(entrada, "%s %d %f", nombre, &edad, &peso);
//    // La alternativa a sscanf es parsear completamente el string
//
//    printf("Has escrito: %s\n", entrada);
//    printf("Nombre: %s\nEdad: %d\nPeso: %.2f", nombre, edad, peso);
//    printf("\nLa cantidad de atributos colocados es: %d", cantEntradas);
    ////////////////////////////// - SSCANF - //////////////////////////////

    // Basicamente, son operaciones contrarias

    ////////////////////////////// - SPRINTF - //////////////////////////////
    char nombre2[20], mensaje[81];
    unsigned int edad2 = 0;
    float peso2 = 0;

    printf("Escriba su nombre: ");
    scanf("%s", nombre2);
    fflush(stdin);
    printf("Escriba su edad: ");
    scanf("%u", &edad2);
    fflush(stdin);
    printf("Escriba su peso: ");
    scanf("%f", &peso2);

    sprintf(mensaje, "%s - %d - %.2f", nombre2, edad2, peso2);
    puts(mensaje);
    ////////////////////////////// - SPRINTF - //////////////////////////////

    return 0;
}
