#include "funciones.h"

int main()
{
    tLista listaEmp,
           listaEst;
    char *pathArchEst = "archEst.dat",
         *pathArchEmp = "archEmp.dat",
         *pathArchEstActu = "archEstActu.dat",
         *pathArchEmpActu = "archEmpActu.dat";

    //crearLista(&listaEst);
    crearLista(&listaEmp);

    cargarEmpleados(pathArchEmp);
    //cargarEstudiantes(pathArchEst);

    //cargarListaEstudiantes(pathArchEst, &listaEst);
    cargarListaEmpleados(pathArchEmp, &listaEmp);

    //actualizarArchivoEst(&listaEst, pathArchEstActu);
    ordenarListaEmp(&listaEmp);
    actualizarArchivoEmp(&listaEmp, pathArchEmpActu);

    //leerArchivoEstudiantes(pathArchEstActu);
    leerArchivoEmpleados(pathArchEmpActu);


    return 0;
}
