#include "funciones.h"

void cargarListaEstudiantes(char* pathArch, tLista* listaEst)
{
    t_estudiante estudiante;
    FILE *pf;
    pf = fopen(pathArch, "rb");

    fread(&estudiante, sizeof(estudiante), 1, pf);

    while(!feof(pf))
    {
        ponerOrdenLista(listaEst, &estudiante, sizeof(estudiante), compararEstudiantes);
        fread(&estudiante, sizeof(t_estudiante), 1, pf);
    }

    fclose(pf);
}

void cargarListaEmpleados(char* pathArch, tLista* listaEmp)
{
    t_empleado empleado;
    FILE *pf;
    pf = fopen(pathArch, "rb");

    fread(&empleado, sizeof(empleado), 1, pf);

    while(!feof(pf))
    {
        ponerAlComienzo(listaEmp, &empleado, sizeof(empleado));
        fread(&empleado, sizeof(t_empleado), 1, pf);
    }

    fclose(pf);
}

void actualizarArchivoEst(tLista* listaEst, char* pathArch)
{
    t_estudiante estudiante;
    FILE *pf;
    pf = fopen(pathArch, "wb");

    while(!listaVacia(listaEst))
    {
        sacarPrimeroLista(listaEst, &estudiante, sizeof(estudiante));
        fwrite(&estudiante, sizeof(estudiante), 1, pf);
    }

    fclose(pf);
}

void actualizarArchivoEmp(tLista* listaEmp, char* pathArch)
{
    t_empleado empleado;
    FILE *pf;

    pf = fopen(pathArch, "wb");

    while(!listaVacia(listaEmp))
    {
        sacarPrimeroLista(listaEmp, &empleado, sizeof(empleado));
        fwrite(&empleado, sizeof(empleado), 1, pf);
    }

    fclose(pf);
}

void ordenarListaEmp(tLista* listaEmp1)
{
    t_empleado empleado;
    tLista listaEmp2;

    crearLista(&listaEmp2);

    while(!listaVacia(listaEmp1))
    {
        sacarPrimeroLista(listaEmp1, &empleado, sizeof(t_empleado));
        ponerOrdenLista(&listaEmp2, &empleado, sizeof(empleado), compararEmpleados);
    }

    while(!listaVacia(&listaEmp2))
    {
        sacarPrimeroLista(&listaEmp2, &empleado, sizeof(t_empleado));
        ponerOrdenLista(listaEmp1, &empleado, sizeof(empleado), compararEmpleados);
    }
}

// Compara por DNI
int compararEstudiantes(const void* est1, const void* est2)
{
    return ((t_estudiante*)est1)->dni > ((t_estudiante*)est2)->dni ? 1 : ((t_estudiante*)est1)->dni < ((t_estudiante*)est2)->dni ? -1 : 0;
}

//Compara por DNI
int compararEmpleados(const void* emp1, const void* emp2)
{
    return ((t_empleado*)emp1)->dni > ((t_empleado*)emp2)->dni ? 1 : ((t_empleado*)emp1)->dni < ((t_empleado*)emp2)->dni ? -1 : 0;
}

int leerArchivoEmpleados(char* pathArchEmp)
{
    FILE *pf = fopen(pathArchEmp, "rb");
    t_empleado empleado;

    if(!pf)
        return 1;

    fread(&empleado, sizeof(t_empleado), 1, pf);

    while(!feof(pf))
    {
        printf("DNI: %d\nAPELLIDO: %s\nNOMBRE: %s\nSUELDO: %.2f\n",
               empleado.dni,
               empleado.nombre,
               empleado.apellido,
               empleado.sueldo);
        printf("========================\n");

        fread(&empleado, sizeof(t_empleado), 1, pf);
    }

    fclose(pf);

    return 0;
}

int leerArchivoEstudiantes(char* pathArchEst)
{
    FILE *pf = fopen(pathArchEst, "rb");
    t_estudiante estudiante;

    if(!pf)
        return 1;

    fread(&estudiante, sizeof(t_estudiante), 1, pf);

    while(!feof(pf))
    {
        printf("DNI: %d\nAPELLIDO: %s\nNOMBRE: %s\PROMEDIO: %.2f\n",
               estudiante.dni,
               estudiante.apellido,
               estudiante.nombre,
               estudiante.promedio);
        printf("========================\n");

        fread(&estudiante, sizeof(t_estudiante), 1, pf);
    }

    fclose(pf);

    return 0;
}

int cargarEstudiantes(char* pathArchEst)
{
    FILE *pf;
    t_estudiante estudVec[] =
    {
        {1236, "Boyle", "Charles", 6.46},
        {1238, "Diaz", "Rosa", 4.50},
        {1240, "Holts", "Raymond", 10},
        {1239, "Jeffords", "Terry", 9},
        {1237, "Linetti", "Gina", 7.92},
        {1234, "Peralta", "Jake", 5.98},
        {1235, "Santiago", "Amy", 9.50}
    };

    pf = fopen(pathArchEst, "wb");

    if(!pf)
        return 1;

    fwrite(&estudVec, sizeof(estudVec), 1, pf);
    fclose(pf);

    return 0;
}

int cargarEmpleados(char* pathArchEmp)
{
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

    pf = fopen(pathArchEmp, "wb");

    if(!pf)
        return 1;

    fwrite(&emplVec, sizeof(emplVec), 1, pf);
    fclose(pf);

    return 0;
}
