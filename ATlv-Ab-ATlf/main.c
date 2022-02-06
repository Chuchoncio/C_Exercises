#include <stdio.h>
#include <stdlib.h>

#define TAM_VEC 5
#define TAM_CAD 100

typedef struct
{
    int d, m, a;
}t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    t_fecha f_nac;
    char estado;
} t_alumno;

int leer_alumno_de_archLF(FILE *pf, t_alumno* alu);
int leer_alumno_de_archLV(FILE *pf, t_alumno* alu);
void leer_archivo_binario(FILE *pf);
void leer_alumno(t_alumno* alu);

int main()
{
    //////////////////////CONVERSION A BIN//////////////////////////////
    FILE *arch_txt_lv, *arch_txt_lf, *arch_bin;
    t_alumno alu[TAM_VEC], alu2[TAM_VEC];
    char cad[TAM_CAD];
    int i = 0;

    arch_txt_lv = fopen("alumnosLV.txt", "rt");
    arch_bin = fopen("alumnos_binLV.bin", "wb");
    arch_txt_lf = fopen("alumnosLF.txt", "wt");

    //Longitud Variable
    while(fgets(cad, sizeof(cad), arch_txt_lv))
    {

        sscanf(cad, "%d|%[^|\n]|%c|%f|%d/%d/%d|%c\n",
                  &alu[i].dni,
                  alu[i].apyn,
                  &alu[i].sexo,
                  &alu[i].promedio,
                  &alu[i].f_nac.d,
                  &alu[i].f_nac.m,
                  &alu[i].f_nac.a,
                  &alu[i].estado);
        fwrite(&alu[i], sizeof(t_alumno), 1, arch_bin);
        i++;
    }

    fclose(arch_bin);
    fclose(arch_txt_lv);

    //////////////////////CONVERSION A TXTLF////////////////////////////
    arch_bin = fopen("alumnos_binLV.bin", "rb");
//    leer_archivo_binario(arch_bin);

    fread(&alu2, sizeof(t_alumno), TAM_VEC, arch_bin);
    for(i = 0; i < TAM_VEC; i++)
    {
        fprintf(arch_txt_lf, "%8d|%-29s|%c|%2.2f|%02d/%02d/%4d|%c\n",
                  alu2[i].dni,
                  alu2[i].apyn,
                  alu2[i].sexo,
                  alu2[i].promedio,
                  alu2[i].f_nac.d,
                  alu2[i].f_nac.m,
                  alu2[i].f_nac.a,
                  alu2[i].estado);
    }

    fclose(arch_bin);
    fclose(arch_txt_lv);


    return 0;
}

void leer_archivo_binario(FILE *pf)
{
    t_alumno alu;

    fread(&alu, sizeof(t_alumno), 1, pf);
    while(!feof(pf))
    {
        leer_alumno(&alu);
        fread(&alu, sizeof(t_alumno), 1, pf);
    }
}

void leer_alumno(t_alumno* alu)
{
    printf("%d",alu->dni);
    printf("|%s",alu->apyn);
    printf("|%c",alu->sexo);
    printf("|%.2f", alu->promedio);
    printf("|%d/%d/%d", alu->f_nac.d, alu->f_nac.m, alu->f_nac.a);
    printf("|%c", alu->estado);
    printf("\n");

}

// Archivos Binarios
int leer_alumno_de_archLF(FILE *pf, t_alumno* alu)
{
    return fscanf(pf, "%8d%29[^\n]%c%5f%2d%2d%4d%c\n",
                  &alu->dni,
                  alu->apyn,
                  &alu->sexo,
                  &alu->promedio,
                  &alu->f_nac.d,
                  &alu->f_nac.m,
                  &alu->f_nac.a,
                  &alu->estado)
                   == 8;
}

int leer_alumno_de_archLV(FILE *pf, t_alumno* alu)
{
    return fscanf(pf, "%d|%[^|\n]|%c|%f|%d/%d/%d|%c\n",
                  &alu->dni,
                  alu->apyn,
                  &alu->sexo,
                  &alu->promedio,
                  &alu->f_nac.d,
                  &alu->f_nac.m,
                  &alu->f_nac.a,
                  &alu->estado)
                   == 8;
}
