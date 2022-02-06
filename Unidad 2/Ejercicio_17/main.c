#include "main.h"

int main()
{
    //cargarEmpleados("arch_emp.txt");
    //cargarEstudiantes("arch_est.txt");

    char bufferEst[100], bufferEmp[100];
    t_empleado empActual;
    t_estudiante estActual;
    FILE *archEmp, *archEst, *archEmpActu;
    float promRequer = 7.00;
    double actuSueldo = 0.0728;
    char *pathArchEst = "arch_est.txt",
         *pathArchEmp = "arch_emp.txt",
         *pathArchEmpActu = "arch_emp_actu.txt";

    archEst = fopen(pathArchEst, "rt");

    if(!archEst)
    {
        printf("Archivo MISSING IN ACTION!");
        return 1;
    }

    archEmp = fopen(pathArchEmp, "rt");

    if(!archEmp)
    {
        printf("Archivo DESAPARECIDOU!");
        return 1;
    }

    archEmpActu = fopen(pathArchEmpActu, "wt");

    if(!archEmpActu)
    {
        printf("Archivo NO ENCONTRADOU!");
        return 1;
    }

    while(fgets(bufferEmp, 100, archEmp) && fgets(bufferEst, 100, archEst))
    {
        sscanf(bufferEmp, "%d %s %s %lf",  &empActual.dni,
                                           empActual.apellido,
                                           empActual.nombre,
                                           &empActual.sueldo);

        sscanf(bufferEst, "%d %s %s %f",   &estActual.dni,
                                     estActual.apellido,
                                     estActual.nombre,
                                     &estActual.promedio);

        if(estActual.promedio > promRequer)
        {
            empActual.sueldo += (empActual.sueldo*actuSueldo);
        }

        fprintf(archEmpActu, "%d %s %s %.2lf\n", empActual.dni,
                                             empActual.apellido,
                                             empActual.nombre,
                                             empActual.sueldo);
    }

    fclose(archEmp);
    fclose(archEmpActu);
    fclose(archEst);

    remove(pathArchEmp);
    rename(pathArchEmpActu, pathArchEmp);

    return 0;
}
