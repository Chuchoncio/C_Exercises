#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int factorial(int n);
double combinatorio(int n, int m);
double calcularE(int x, float tol);
float calcularRaizCuadrada(int a, double tol);
int esFibonacci(int num);
double obtenerSeno(double x, double tol);

#endif // MATEMATICA_H_INCLUDED
