#include "Persona.h"

Persona::Persona(string nom, string dir, char sex, string fn)
: nombre(nom), direccion(dir), sexo(sex), f_nac(fn)
{

}

Persona::Persona()
{

}

string Persona::getNombre()
{
    return this->nombre;
}

string Persona::getDireccion()
{
    return this->direccion;
}

char Persona::getSexo()
{
    return this->sexo;
}

string Persona::getFechaNac()
{
    return this->f_nac;
}

ostream& operator<<(ostream& op, Persona& per)
{
    op << per.getNombre() << " " << per.getDireccion() << " "
       << per.getFechaNac() << " " << per.getSexo() << endl;

    return op;
}

//////////////////////////////////////////////////////////////////////////////////

Estudiante::Estudiante(string nom, string dir, char sex, string fn, float notFin)
: Persona(nom, dir, sex, fn)
{
    this->notaFinal = notFin;
}

Estudiante::Estudiante()
{

}

float Estudiante::getNotaFinal()
{
    return this->notaFinal;
}

void Estudiante::setNotaFinal(float nf)
{
    this->notaFinal = nf;
}

ostream& operator<<(ostream& op, Estudiante& est)
{
    op << est.getNombre() << " " << est.getDireccion() << " "
       << est.getFechaNac() << " " << est.getSexo() << " "
       << est.notaFinal << endl;

    return op;
}

//////////////////////////////////////////////////////////////////////////////////

Empleado::Empleado(string nom, string dir, char sex, string fn, double sue)
: Persona(nom, dir, sex, fn)
{
    this->sueldo = sue;
}

Empleado::Empleado()
{

}

double Empleado::getSueldo()
{
    return this->sueldo;
}

void Empleado::setSueldo(double sue)
{
    this->sueldo = sue;
}

ostream& operator<<(ostream& op, Empleado& emp)
{
    op << emp.getNombre() << " " << emp.getDireccion() << " "
       << emp.getFechaNac() << " " << emp.getSexo() << " "
       << emp.getSueldo() << endl;

    return op;
}

//////////////////////////////////////////////////////////////////////////////////

Estudiante_Empleado::Estudiante_Empleado(string nom, string dir, char sex, string fn, float notFin, double sue)
: Persona(nom, dir, sex, fn)
{
    this->setNotaFinal(notFin);
    this->setSueldo(sue);
}

ostream& operator<<(ostream& op, Estudiante_Empleado& estEmp)
{
    op << estEmp.getNombre() << " " << estEmp.getDireccion() << " "
       << estEmp.getFechaNac() << " " << estEmp.getSexo() << " "
       << estEmp.getNotaFinal() << " " << estEmp.getSueldo() << endl;

    return op;
}

//////////////////////////////////////////////////////////////////////////////////


