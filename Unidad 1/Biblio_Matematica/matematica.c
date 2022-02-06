#include "matematica.h"

#define PI 3.14159265
#define ABS(X) ( (X) < 0 ? (X)*(-1) : (X) )

long int factorial(int n)
{
    if(n == 1)
        return n;

    return n*factorial(n-1);
}

double combinatorio(int n, int m)
{
    return factorial(m) / (factorial(n)*factorial(m-n));
}

double calcularE(int x, float tol)
{
    double e;
    int n;
    double calculo;

    e = n = 1;

    do
    {
        calculo = (pow(x,n)/factorial(n));
        e += calculo;
        n++;
    }while((tol <= e));

    return e;
}

float calcularRaizCuadrada(int a, double tol)
{
    float ri = 1;
    float r;

    do
    {
        ri = r;
        r = (0.5) * (ri + (a/ri));

    }while(tol <= (r-ri) || tol <= (ri-r));

    return r;
}

int esFibonacci(int num)
{
    int fibo = 1;
    int i = 0;

    printf("Serie Fibonacci: \n");

    while(fibo < 100)
    {
        fibo += i;
        i = fibo-i;

        printf("%d ", fibo);

        if(num == fibo)
            return 1;
    }

    return 0;
}

double obtenerSeno(double num, double TOL)
{
    double rad = num*(PI/180),
           resultado = rad,
           termino = rad;
    int exp = 3;

    while(ABS(termino) > TOL)
    {
        termino *= -(rad*rad)/(exp*(exp-1));
        resultado += termino;
        exp+=2;
    }

    return resultado;
}
