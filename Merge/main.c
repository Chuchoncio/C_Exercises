#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float nota1, nota2, nota3;
} t_notas;

typedef struct
{
    int d, m, a;
} t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float prom;
    t_notas notas;
    t_fecha fechaIng;
    char estado;
} t_alumno;

int cargar_archivo1(char * path);
int cargar_archivo2(char * path);

int main()
{
    FILE *pf1, *pf2, *pfr;
    t_alumno alu1, alu2;

    cargar_archivo1("alu1.dat");
    cargar_archivo2("alu2.dat");

    pf1 = fopen("alu1.dat", "rb");

    if(!pf1)
        return 1;

    pf2 = fopen("alu2.dat", "rb");

    if(!pf2)
        return 1;

    pfr = fopen("alu_res.dat", "wb");

    if(!pfr)
    {
        fclose(pf1);
        fclose(pf2);
        return 3;
    }

    ///UNION (Ordenar antes)
//    fread(&alu1, sizeof(t_alumno), 1, pf1);
//    fread(&alu2, sizeof(t_alumno), 1, pf2);
//
//    while(!feof(pf1) && !feof(pf2))
//    {
//        if(alu1.dni < alu2.dni)
//        {
//            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
//            fread(&alu1, sizeof(t_alumno), 1, pf1);
//        }
//        else if(alu1.dni > alu2.dni)
//        {
//            fwrite(&alu2, sizeof(t_alumno), 1, pfr);
//            fread(&alu2, sizeof(t_alumno), 1, pf2);
//        }
//        else
//        {
//            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
//            fread(&alu1, sizeof(t_alumno), 1, pf1);
//            fread(&alu2, sizeof(t_alumno), 1, pf2);
//        }
//    }
//
//    while(!feof(pf1))
//    {
//        fwrite(&alu1, sizeof(t_alumno), 1, pfr);
//        fread(&alu1, sizeof(t_alumno), 1, pf1);
//    }
//    while(!feof(pf2))
//    {
//        fwrite(&alu2, sizeof(t_alumno), 1, pfr);
//        fread(&alu2, sizeof(t_alumno), 1, pf2);
//    }

    ///INTERSECCION (Ordenar antes)
    fread(&alu1, sizeof(t_alumno), 1, pf1);
    fread(&alu2, sizeof(t_alumno), 1, pf2);

    while(!feof(pf1) && !feof(pf2))
    {
        if(alu1.dni < alu2.dni)
            fread(&alu1, sizeof(t_alumno), 1, pf1);
        else if(alu1.dni > alu2.dni)
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        else
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
            fread(&alu2, sizeof(t_alumno), 1, pf2);

        }
    }

    fclose(pf1);
    fclose(pf2);
    fclose(pfr);

    pfr = fopen("alu_res.dat", "rb");

    if(!pfr)
        return 1;

    fread(&alu1, sizeof(t_alumno), 1, pfr);
    while(!feof(pfr))
    {
        printf("\n%ld - %d, %s, %02d/%02d/%d, %c",
               ftell(pfr), alu1.dni,
               alu1.apyn, alu1.fechaIng.d,
               alu1.fechaIng.m, alu1.fechaIng.a,
               alu1.estado);
        fread(&alu1, sizeof(t_alumno), 1, pfr);
    }


    return 0;
}

int cargar_archivo1(char * path)
{
    t_alumno alu_vec[] = {
                         {90, "Sa, Lia", 'F', 7.5, {7,8}, {1,2,2005}, 'A'},
                         {98, "Jose Perez", 'M', 8, {7,8,9},{1,2,1999},'A'},
                         {110, "Alumno Uno", 'F', 7.5, {7,8}, {1,2,2005},'I'},
                         {115, "Alumno Jodedor", 'M', 9, {9,9}, {1,2,1998},'A'},
                         {130, "Alumno Tres", 'M', 8,{7,8}, {1,2,2000},'A'},
                         {450, "Alumno Cinco", 'F', 4, {7,8}, {1,2,1997}, 'A'}
                         };

    FILE * pf = fopen(path, "wb");
    if(!pf)
    {
        printf("Archivo pifiado!");
        return 1;
    }

    fwrite(&alu_vec, sizeof(alu_vec), 1, pf);

    fclose(pf);

    return 0;
}

int cargar_archivo2(char * path)
{
    t_alumno alu_vec[] = {
                         {90, "Salsedo, Fernando", 'M', 7.5, {7,8}, {1,2,2005}, 'A'},
                         {97, "Martina Peralta", 'F', 8, {7,8,9},{1,2,1999},'A'},
                         {105, "Hipergola Juan Manuel", 'M', 7.5, {7,8}, {1,2,2005},'I'},
                         {115, "Alumno Jodedor", 'M', 9, {9,9}, {1,2,1998},'A'},
                         {120, "Alumno Cuatro", 'M', 8,{7,8}, {1,2,2000},'A'},
                         {200, "Alumno Seis", 'F', 4, {7,8}, {1,2,1997}, 'A'}
                         };

    FILE * pf = fopen(path, "wb");
    if(!pf)
    {
        printf("Archivo pifiado!");
        return 1;
    }

    fwrite(&alu_vec, sizeof(t_alumno), 5, pf);

    fclose(pf);

    return 0;
}
