#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    tFecha fecha1;
    tFecha fecha2;

    printf("Ingrese fecha 1: ");
    scanf("%d/%d/%d", &fecha1.dia, &fecha1.mes, &fecha1.anio);

    printf("Dia de la semana: %d", diaDeLaSemana(fecha1));

//    printf("Ingrese fecha 2: ");
//    scanf("%d/%d/%d", &fecha2.dia, &fecha2.mes, &fecha2.anio);

//    if( fecha_correcta(&fecha1) )
//        printf("\nLa fecha es formalmente correcta.");
//    else
//        printf("\nLa fecha NO es formalmente correcta.");
//
//    dia_siguiente(&fecha1);
//    printf("\n%d/%d/%d", fecha1.dia, fecha1.mes, fecha1.anio);

//    printf("Ingrese cantidad de dias a sumar: "); scanf("%d", &cantDias);
//    sumar_Ndias(&fecha1, cantDias);
//    printf("\n%d/%d/%d", fecha1.dia, fecha1.mes, fecha1.anio);

//    printf("Ingrese cantidad de dias a restar: "); scanf("%d", &cantDias);
//    restar_Ndias(&fecha1, cantDias);
//    printf("\n%d/%d/%d", fecha1.dia, fecha1.mes, fecha1.anio);

//    printf("Cantidad de dias entre ambas fechas: %d", cantDiasEntreDosFechas(fecha1, fecha2));

    return 0;
}
