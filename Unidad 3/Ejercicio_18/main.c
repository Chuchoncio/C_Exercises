#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"

#define MALA_APERTURA 1

typedef struct
{
    int dni;
    char apellido[15],
         nombre[15];
    double sueldo;
} t_empleado;

int cargarEmpleados(char* pathArchEmp);
int leerArchivoEmpleados(char* pathArchEmp);
void ordenarArchivo(char* pathArchEmp, char* pathArchEmpOrd);
void cargarRegistrosEnPila(char* pathArchEmp, tPila* pila);

int main()
{
    char* pathArchEmp = "empleados.dat";
    char* pathArchEmpOrd = "empleados_ord.dat";

    cargarEmpleados(pathArchEmp);

    ordenarArchivo(pathArchEmp, pathArchEmpOrd);

    //cargarPilaEnArchivo(pathArchEmpOrd);

    leerArchivoEmpleados(pathArchEmpOrd);


    return 0;
}

void ordenarArchivo(char* pathArchEmp, char* pathArchEmpOrd)
{
    tPila pilaEnt, pilaAux, pilaRes;
    t_empleado emp1, emp2;

    crear_pila(&pilaEnt);
    crear_pila(&pilaAux);
    crear_pila(&pilaRes);

    cargarRegistrosEnPila(pathArchEmp, &pilaEnt);

    while(!pila_vacia(&pilaEnt))
    {
        sacar_de_pila(&pilaEnt, &emp1, sizeof(t_empleado));
        if(pila_vacia(&pilaRes))
        {
            poner_en_pila(&pilaRes, &emp1, sizeof(t_empleado));
            while(!pila_vacia(&pilaAux))
            {
                sacar_de_pila(&pilaAux, &emp1, sizeof(t_empleado));
                poner_en_pila(&pilaRes, &emp1, sizeof(t_empleado));
            }
        }else
        {
            ver_tope_pila(&pilaRes, &emp2, sizeof(t_empleado));
            if(emp1.dni <= emp2.dni)
            {
                poner_en_pila(&pilaRes, &emp1, sizeof(t_empleado));
                sacar_de_pila(&pilaAux, &emp1, sizeof(t_empleado));
                poner_en_pila(&pilaRes, &emp1, sizeof(t_empleado));
            }else
            {
                sacar_de_pila(&pilaRes, &emp1, sizeof(t_empleado));
                poner_en_pila(&pilaAux, &emp1, sizeof(t_empleado));
            }
        }
    }
}

void cargarRegistrosEnPila(char* pathArchEmp, tPila* pila)
{
    FILE *archEmp;
    archEmp = fopen(pathArchEmp, "rb");
    t_empleado emp;

    if(!archEmp)
    {
        printf("Error al operar sobre el archivo %s", pathArchEmp);
        exit(1);
    }

    fread(&emp, sizeof(t_empleado), 1, archEmp);
    while(!feof(archEmp))
    {
        poner_en_pila(pila, &emp, sizeof(emp));
        fread(&emp, sizeof(t_empleado), 1, archEmp);
    }

    fclose(archEmp);
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

int cargarEmpleados(char* pathArchEmp)
{
    FILE *pf;
    t_empleado emplVec[] =
    {
        {6, "Boyle", "Charles", 47000},
        {8, "Diaz", "Rosa", 49000},
        {0, "Holts", "Raymond", 70000},
        {9, "Jeffords", "Terry", 60000},
        {7, "Linetti", "Gina", 40000},
        {4, "Peralta", "Jake", 50000},
        {5, "Santiago", "Amy", 55000}
    };

    pf = fopen(pathArchEmp, "wb");

    if(!pf)
        return MALA_APERTURA;

    fwrite(&emplVec, sizeof(emplVec), 1, pf);
    fclose(pf);

    return 0;
}
