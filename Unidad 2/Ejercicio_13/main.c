#include "funciones.h"

int main()
{
    t_empleado empActual;
    t_estudiante estActual;
    FILE *archEmp, *archEst, *archEmpActu;
    float promRequer = 7.00;
    double actuSueldo = 0.0728;
    char *pathArchEst = "arch_est.dat",
         *pathArchEmp = "arch_emp.dat",
         *pathArchEmpActu = "arch_emp_actu.dat";

    cargarEstudiantes(pathArchEst);
    cargarEmpleados(pathArchEmp);

    archEst = fopen(pathArchEst, "rb");

    if(!archEst)
    {
        printf("Archivo MISSING IN ACTION!");
        return 1;
    }

    archEmp = fopen(pathArchEmp, "rb");

    if(!archEmp)
    {
        printf("Archivo DESAPARECIDOU!");
        return 1;
    }

    archEmpActu = fopen(pathArchEmpActu, "wb");

    if(!archEmpActu)
    {
        printf("Archivo NO ENCONTRADOU!");
        return 1;
    }

    fread(&estActual, sizeof(t_estudiante), 1, archEst);
    fread(&empActual, sizeof(t_empleado), 1, archEmp);
    while(!feof(archEst) && !feof(archEmp))
    {
        if(estActual.promedio > promRequer)
            empActual.sueldo += (empActual.sueldo * actuSueldo);

        fwrite(&empActual, sizeof(t_empleado), 1, archEmpActu);

        fread(&estActual, sizeof(t_estudiante), 1, archEst);
        fread(&empActual, sizeof(t_empleado), 1, archEmp);
    }


    fclose(archEst);
    fclose(archEmp);
    fclose(archEmpActu);

    leerArchivoEmpleados(pathArchEmpActu);

    return 0;
}
