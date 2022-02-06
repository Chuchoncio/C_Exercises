#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>

typedef struct {
    int dia,
        mes,
        anio;
} t_fecha;

int fecha_correcta(const t_fecha *fecha1);
int cantidad_dias_mes(const int mes, const int anio);
int es_bisiesto(const int anio);
void dia_siguiente(t_fecha *fecha1);
void sumar_Ndias(t_fecha *fecha1, int nDias);
void restar_Ndias(t_fecha *fecha1, int nDias);
int compara_fecha(const t_fecha *fecha1, const t_fecha *fecha2);
void ingresa_fecha(t_fecha* fecha);
void mostrar_fecha(t_fecha* fecha);
void suma_anios(t_fecha *fecha, int anios);

#endif // FECHA_H_INCLUDED
