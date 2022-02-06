#include "fecha.h"

// Ejercicio 14
int fecha_correcta(const tFecha *fecha1)
{
    if( fecha1->anio >= 1600 )
    {
        if( fecha1->mes >= 1 && fecha1->mes <= 12)
        {
            if( fecha1->dia >= 1 && fecha1->dia <= cantidad_dias_mes(fecha1->mes, fecha1->anio) )
                return 1;
        }
    }

    return 0;
}

int cantidad_dias_mes(const int mes, const int anio)
{
    int cant_dias[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };

    // Si es bisiesto, accede a la segunda fila de la matriz vectorMes
    return cant_dias[es_bisiesto(anio)][mes - 1];
}

int es_bisiesto(const int anio)
{
    if( anio%400 == 0 || ( anio%4 == 0 && anio%100 != 0 ))
        return 1;

    return 0;
}

// Ejercicio 15
void dia_siguiente(tFecha *fecha1)
{
    if( fecha_correcta(fecha1) )
    {
        fecha1->dia++;
        if( fecha1->dia > cantidad_dias_mes(fecha1->mes, fecha1->anio) )
        {
            fecha1->mes++;
            fecha1->dia = 1;
            if( fecha1->mes > 12 )
            {
                fecha1->mes = 1;
                fecha1->anio++;
            }
        }
    }
    else
        printf("Fecha invalida.\n");
}

// Ejercicio 16
void sumar_Ndias(tFecha *fecha1, int nDias)
{
    while(nDias)
    {
        fecha1->dia++;
        if( fecha1->dia > cantidad_dias_mes(fecha1->mes, fecha1->anio) )
        {
            fecha1->mes++;
            fecha1->dia = 1;
            if( fecha1->mes > 12 )
            {
                fecha1->mes = 1;
                fecha1->anio++;
            }
        }
        --nDias;
    }
}

// Ejercicio 17
void restar_Ndias(tFecha *fecha1, int nDias)
{
    while(nDias)
    {
        fecha1->dia--;
        if( fecha1->dia < 1 )
        {
            fecha1->mes--;
            if( fecha1->mes < 1 )
            {
                fecha1->mes = 12;
                fecha1->anio--;
            }
            fecha1->dia = cantidad_dias_mes(fecha1->mes, fecha1->anio);
        }
        --nDias;
    }
}

int compara_fechas(tFecha *fecha1, tFecha *fecha2)
{
    if(fecha1->anio > fecha2->anio)
        return 1;
    else if(fecha1->anio < fecha2->anio)
        return 2;
    else
    {
        if(fecha1->mes > fecha2->mes)
            return 1;
        else if(fecha1->mes < fecha2->mes)
            return 2;
        else
        {
            if(fecha1->dia > fecha2->dia)
                return 1;
            else if(fecha1->dia < fecha2->dia)
                return 2;
            else
                return 0;
        }
    }
}

// Ejercicio 18
int cantDiasEntreDosFechas(tFecha fecha1, tFecha fecha2)
{
    int cantDias = 0;
    tFecha fechaMenor, fechaMayor;
    int comp = compara_fechas(&fecha1, &fecha2);

    if( comp == 1)
    {
        fechaMenor = fecha2;
        fechaMayor = fecha1;
    }
    else if( comp == 2)
    {
        fechaMenor = fecha1;
        fechaMayor = fecha2;
    }
    else
    {
        printf("Las fechas son iguales!\n");
        return -1;
    }

    while( (comp = compara_fechas(&fechaMenor, &fechaMayor)) != 0)
    {
        fechaMenor.dia++;
        cantDias++;
        if( fechaMenor.dia > cantidad_dias_mes(fechaMenor.mes, fechaMenor.anio) )
        {
            fechaMenor.mes++;
            fechaMenor.dia = 1;
            if( fechaMenor.mes > 12 )
            {
                fechaMenor.mes = 1;
                fechaMenor.anio++;
            }
        }
    }

    return cantDias;
}

/**
    Suponiendo que cada mes empieza en Domingo
    0 = Domingo
    1 = Lunes
    2 = Martes
    3 = Miercoles
    4 = Jueves
    5 = Viernes
    6 = Sabado

    Fecha: 13/05 (no importa el año)

    Dia - 1 semana = 13 - 7 = 6 ==> Sabado

  */
int diaDeLaSemana(tFecha fecha)
{
    int dia = fecha.dia;

    while(dia > 6)
        dia -= 7;

    return dia;
}
