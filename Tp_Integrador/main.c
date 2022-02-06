#include "alumno.h"
#include "funciones.h"
#include "fecha.h"
#include "cadenas.h"
#include "archivos.h"

#define TAM         2
#define TAM_LINEA 100

int main()
{
    t_fecha fecha_proceso;
    char path_txt[TAM_LINEA], cadena_txt[TAM_LINEA];
    FILE *arch_txt, *arch_bin, *arch_error;
//    t_alumno vAlum[TAM]={
//                   {1000000," Pepe , Galleta",{01,03,2010},'M',{22,03,1999},"ADM",15,{01,03,2015},'R',{31,12,9999}},
//                   {4444,"Juan,   Galleta ",{01,03,2010},'M',{22,03,1999},"ADM",15,{01,03,2015},'R',{31,12,9999}},
//                    };
    t_alumno alumno;

    /************************************************/
    /// 1 - fecha de proceso
    /************************************************/
    printf("Ingrese la fecha de proceso:\n");
    ingresa_fecha(&fecha_proceso);
    mostrar_fecha(&fecha_proceso);
    puts("\n");

    /************************************************/
    /// 2 - Ingreso el path del archivo de texto
    /************************************************/
    do
    {
        printf("Ingrese path de Archivo de texto:\n");
        fflush(stdin);
        gets(path_txt); /// archivos/mi_archivo.txt

        arch_txt = fopen(path_txt, "rt");

        if(!arch_txt)
            printf("Archivo no encontrado.\n");

    }while(!arch_txt);

    /************************************************/
    /// 3 - Creo el archivo binario y de error
    /************************************************/
    arch_bin = fopen("archivos/mi_archivo.bin", "wb"); /// archivos/mi_archivo.bin
    if(!arch_bin)
    {
        printf("Error al crear archivo binario.");
        exit(1);
    }

    arch_error = fopen("archivos/error.txt", "wt");
    if(!arch_error)
    {
        printf("Error al crear archivo error.");
        exit(1);
    }

    /************************************************/
    /// 4 - Procesamiento de los archivos
    /************************************************/
    while( fgets(cadena_txt, TAM_LINEA, arch_txt) )
    {
        ///pasar esa cadena a la estructura alumno
        if( texto_a_alumno(cadena_txt, &alumno, &fecha_proceso) )
            grabar_binario(arch_bin, &alumno);
        else
            grabar_error(arch_error, cadena_txt);
    }


//    for(i = 0; i < TAM; i++)
//    {
//        if( valida_alumno(&fecha_proceso, &vAlum[i]) )
//        {
//            graba_binario(arch_bin, &vAlum[i]);
//        }
//    }



    /************************************************/
    /// 5 - Cerrar archivos abiertos
    /************************************************/
    fclose(arch_bin);
    fclose(arch_error);
    fclose(arch_txt);

    // mostrar archivo binario generado
    muestra_binario("archivos/mi_archivo.bin");


    return 0;
}
