#include "fecha.h"

#define COMP(dato1, dato2) ( (dato1) == (dato2) ?    \
                             (0) : (dato1) > (dato2) ? \
                             (1) : (-1) )

int fecha_correcta(const t_fecha *fecha1)
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

void dia_siguiente(t_fecha *fecha1)
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

void sumar_Ndias(t_fecha *fecha1, int nDias)
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

void restar_Ndias(t_fecha *fecha1, int nDias)
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

int compara_fecha(const t_fecha *fecha1, const t_fecha *fecha2)
{
    //if(COMP())


    return 1;
}

void ingresa_fecha(t_fecha* fecha)
{
    int es_correcta;
    do{
        fflush(stdin);
        scanf("%d/%d/%d",&fecha->dia,&fecha->mes,&fecha->anio);
        es_correcta = fecha_correcta(fecha);

        if(!es_correcta){
            printf("FECHA INCORRECTA\n");
        }
    }while(!es_correcta);
}

void mostrar_fecha(t_fecha* fecha)
{
    printf("%d/%d/%d", fecha->dia, fecha->mes, fecha->anio);
}

void suma_anios(t_fecha *fecha, int anios)
{
    fecha->anio += anios;

    if( fecha->dia == 29 && fecha->mes == 2 && !es_bisiesto(fecha->anio))
        fecha->dia = 28;

}
