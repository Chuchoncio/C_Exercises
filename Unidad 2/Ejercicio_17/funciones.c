#include "main.h"

int leerArchivoEmpleados(char* pathArchEmp)
{
    FILE *pf = fopen(pathArchEmp, "rb");
    t_empleado empleado;

    if(!pf)
        return 1;

    fread(&empleado, sizeof(t_empleado), 1, pf);

    printf("========================\n");
    while(!feof(pf))
    {
        printf("DNI: %d\nAPELLIDO: %s\nNOMBRE: %s\nSUELDO: %.2f\n",
               empleado.dni,
               empleado.apellido,
               empleado.nombre,
               empleado.sueldo);
        printf("========================\n");

        fread(&empleado, sizeof(t_empleado), 1, pf);
    }

    fclose(pf);

    return 0;
}

int cargarEstudiantes(char* pathArchEst)
{
    int i = 0;
    FILE *pf;
    t_estudiante estudVec[] =
    {
        {1236, "Boyle", "Charles", 6.46},
        {1238, "Diaz", "Rosa", 4.50},
        {1240, "Holts", "Raymond", 10},
        {1239, "Jeffords", "Terry", 9},
        {1237, "Linetti", "Gina", 7.92},
        {1234, "Peralta", "Jake", 5.98},
        {1235, "Santiago", "Amy", 9.5}
    };

    pf = fopen(pathArchEst, "wt");

    if(!pf)
        return MALA_APERTURA;

    while(i < 7)
    {
        fprintf(pf, "%d %s %s %.2f\n", estudVec[i].dni,
                                     estudVec[i].apellido,
                                     estudVec[i].nombre,
                                     estudVec[i].promedio);
        i++;
    }

    fclose(pf);

    return 0;
}

int cargarEmpleados(char* pathArchEmp)
{
    int i = 0;
    FILE *pf;
    t_empleado emplVec[] =
    {
        {1236, "Boyle", "Charles", 47000},
        {1238, "Diaz", "Rosa", 49000},
        {1240, "Holts", "Raymond", 70000},
        {1239, "Jeffords", "Terry", 60000},
        {1237, "Linetti", "Gina", 40000},
        {1234, "Peralta", "Jake", 50000},
        {1235, "Santiago", "Amy", 55000}
    };

    pf = fopen(pathArchEmp, "wt");

    if(!pf)
        return MALA_APERTURA;

    while(i < 7)
    {
        fprintf(pf, "%d %s %s %.0f\n", emplVec[i].dni,
                                     emplVec[i].apellido,
                                     emplVec[i].nombre,
                                     emplVec[i].sueldo);
        i++;
    }

    fclose(pf);

    return 0;
}
