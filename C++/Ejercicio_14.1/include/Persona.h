#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona
{
    public:
        Persona(string nom, string dir, char sex, string fn);
        Persona();
        void mostrarDatos();
        friend ostream& operator<<(ostream& op, Persona& per);


        // GETTERS
        string getNombre();
        string getDireccion();
        char getSexo();
        string getFechaNac();

    private:
        string nombre;
        string direccion;
        char sexo;
        string f_nac;
};

class Estudiante : virtual public Persona
{
    public:
        Estudiante(string nom, string dir, char sex, string fn, float notFin);
        Estudiante();
        float getNotaFinal();
        void setNotaFinal(float nf);
        friend ostream& operator<<(ostream& op, Estudiante& est);

    private:
        float notaFinal;
};

class Empleado : virtual public Persona
{
    public:
        Empleado(string nom, string dir, char sex, string fn, double sue);
        Empleado();
        void setSueldo(double sue);
        double getSueldo();
        friend ostream& operator<<(ostream& op, Empleado& emp);

    private:
        double sueldo;
};

class Estudiante_Empleado : public Estudiante, public Empleado
{
    public:
        Estudiante_Empleado(string nom, string dir, char sex, string fn, float notFin, double sue);
        friend ostream& operator<<(ostream& op, Estudiante_Empleado& estEmp);

    private:
};

#endif // PERSONA_H
