#include "archivos.h"

void grabar_binario(FILE* arch_bin, t_alumno* alumno)
{
    fwrite(alumno, sizeof(t_alumno), 1, arch_bin);
}

int texto_a_alumno(const char* cadena_txt, t_alumno* alumno, t_fecha* fecha_proceso)
{
    ///pasar la cadena recibida a la estructura alumnno y validar
    char aux[100]; /// todo: armar archivo con las macros
    char* ptr;
    int no_informa_fecha_proceso = 0;

    strcpy(aux, cadena_txt);

    /******************************/
    ///fecha de baja
    /******************************/
    alumno->fecha_baja.dia = 31;
    alumno->fecha_baja.mes = 12;
    alumno->fecha_baja.anio = 9999;

    /******************************/
    ///estado
    /******************************/
    alumno->estado = 'R';

    /******************************/
    ///fecha aprobacion ultima materia
    /******************************/
    ptr = strrchr(aux, '\n');
    *ptr = '\0';

    if( cantidad_apariciones(aux, '|') == 7) /// me informa la fecha de ultima aprobacion
    {
        ptr = strrchr(aux, '|');
        sscanf(ptr+1, "%d/%d/%d", &alumno->fecha_aprob_ult.dia,
                                  &alumno->fecha_aprob_ult.mes,
                                  &alumno->fecha_aprob_ult.anio);
        *ptr = '\0';

        printf("%d/%d/%d", alumno->fecha_aprob_ult.dia,
                           alumno->fecha_aprob_ult.mes,
                           alumno->fecha_aprob_ult.anio);

    }
    else /// asume la fecha de ingreso
        no_informa_fecha_proceso = 1;

    ///cantidad_materias_aprobadas
    ///carrera
    ///fecha_ingreso


    return 1;
}

void grabar_error(FILE* arch_error, const char* cadena_txt)
{

}

void muestra_binario(const char* nombre_archivo)
{

}
