#include "alumno.h"

#define ERROR 1
#define OKAY 0
#define ANIOS 10

int valida_alumno(const t_fecha *fecha, t_alumno *alumno)
{
    t_fecha fecha_aux;

    /// DNI
    if(alumno->dni <= 10000 || alumno->dni >= 100000000)
        return ERROR;

    fecha_aux = alumno->fecha_nac;

    suma_anios(&fecha_aux, ANIOS);

    ///FECHA NACIMIENTO
    if( !fecha_correcta(&alumno->fecha_nac) )
        return ERROR;

    /// SEXO
    if( alumno->sexo != 'M' && alumno->sexo != 'F')
        return ERROR;


    return OKAY;
}

/************************************************/

int ingresa_alumno(t_alumno* alumno)
{



    return 1;
}

/************************************************/

void normaliza_apellido_nombre(t_alumno* alumno)
{
    mayusculasMinusculas(alumno->apyn);
    no_mas_de_un_espacio(alumno->apyn);
    sin_espacios_inicio_fin(alumno->apyn);
    coma(alumno->apyn);
}


