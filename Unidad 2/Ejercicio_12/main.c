#include <stdio.h>
#include <stdlib.h>

#define LARGOTEXTO 50
#define CANTNOTAS 3
#define CANTALUM 5

void cargarAlum(char* mtx_nom[LARGOTEXTO], float mtx_notas[][CANTNOTAS], float sumPromGen[], int* cantAlCarg);

int main()
{
    char** mtx_alumnos;
    int cantAlumCargados = 0, i, j;
    float mtx_notas[CANTALUM][CANTNOTAS], sumaPromGeneral[CANTALUM-2] = {0};
    FILE *pf;

    mtx_alumnos = (char**)malloc(LARGOTEXTO);

    cargarAlum(mtx_alumnos, mtx_notas, sumaPromGeneral, &cantAlumCargados);

    pf = fopen("datosAlumnos.txt", "wt");

    if(!pf)
        exit(1);

    system("cls");
    fprintf(pf, "   Apellido/s, Nombre/s  P. 1  P. 2 Prom.\n");
    fprintf(pf, "   ==================== ===== ===== =====\n");
    for(i = 0; i < cantAlumCargados; i++)
    {
        fprintf(pf, "%2d ", i);
        fprintf(pf, "%-*s ", 20, mtx_alumnos[i]);
        for(j = 0; j < CANTNOTAS; j++)
        {
            fprintf(pf, "%5.2f ", mtx_notas[i][j]);
        }
        fprintf(pf, "\n");
    }

    fprintf(pf, "%-*c", 24, ' ');
    for(i = 0; i < CANTNOTAS; i++)
    {
        fprintf(pf, "%5.2f ",(float)sumaPromGeneral[i]/cantAlumCargados);
    }

    fclose(pf);

    system("notepad.exe datosAlumnos.txt");
    system("exit");

    free(mtx_alumnos);

    return 0;
}

void cargarAlum(char* mtx_nom[LARGOTEXTO], float mtx_notas[][CANTNOTAS],
                float sumPromGen[], int* cantAlCarg)
{
    int i, j;
    float sumaPromAlum = 0;

    for(i = 0; i < CANTALUM-3; i++)
    {
        printf("Ingrese alumno %d: ", i+1);
        mtx_nom[i] = (char*)malloc(LARGOTEXTO);
        gets(mtx_nom[i]);

        for(j = 0; j < CANTNOTAS-1; j++)
        {
            printf("Nota %d: ", j+1);
            scanf("%f", &mtx_notas[i][j]);
            sumaPromAlum += mtx_notas[i][j];
            sumPromGen[j] += mtx_notas[i][j];
        }
        mtx_notas[i][CANTNOTAS-1] = sumaPromAlum / (CANTNOTAS-1);
        sumPromGen[CANTALUM-3] += mtx_notas[i][CANTNOTAS-1];
        fflush(stdin);
        (*cantAlCarg)++;
        sumaPromAlum = 0;
    }
}
