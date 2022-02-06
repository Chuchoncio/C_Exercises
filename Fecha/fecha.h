#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>

typedef struct {
    int dia,
        mes,
        anio;
} tFecha;

int fecha_correcta(const tFecha *fecha1);
int cantidad_dias_mes(const int mes, const int anio);
int es_bisiesto(const int anio);
void dia_siguiente(tFecha *fecha1);
void sumar_Ndias(tFecha *fecha1, int nDias);
void restar_Ndias(tFecha *fecha1, int nDias);
int compara_fechas(tFecha *fecha1, tFecha *fecha2);
int cantDiasEntreDosFechas(tFecha fecha1, tFecha fecha2);
int diaDeLaSemana(tFecha fecha);

#endif // FECHA_H_INCLUDED
