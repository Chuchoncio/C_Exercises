#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Persona.h"

using namespace std;

void mostrarPersonas(list<Persona>& personas)
{
    for(list<Persona>::iterator it = personas.begin(); it != personas.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    list<Persona> personas;
    Persona pibe1("Flavio", "Padua", 'G', "11-1-1997");
    Estudiante est1("Chuchu", "25 de Mayo", 'M', "5-5-1996", 8.5);
    Empleado emp1("Matias", "French 717", 'F', "18-10-1990", 50000);
    Estudiante_Empleado estEmp1("Yulian", "Quilmes", 'T', "9-6-1997", 6.5, 10000);

    personas.push_back(pibe1);
    personas.push_back(est1);
    personas.push_back(emp1);
    personas.push_back(estEmp1);

    mostrarPersonas(personas);

    return 0;
}
