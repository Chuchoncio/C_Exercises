#include "main.h"

/**
    La idea es darse cuenta que la primera forma de operar sobre el vector
        es la mas eficiente porque no utiliza un struct (que vendria a tener
        el mismo peso que si las variables del mismo fuesen individuales),
        pero la realidad es que solamente complica la lectura y es innecesario,
        mas no es mejor en cuanto a tiempo de uso.
        La segunda alternativa es mas util cuando existen mayor cantidad de
        operaciones a realizar sobre un vector.
  */

//int main()
//{
//    int vecVar[TAMVEC] = {0}, tam = 0;
//    long sumaElemVec = 0;
//
//    ingresarVectorVariable(vecVar, &tam);
//
//    printf("El promedio de los elementos del vector es: %.2f\n",
//           sumaYPromedio(vecVar, tam, &sumaElemVec));
//    printf("La suma de los elementos del vector es: %ld\n", sumaElemVec);
//
//
//    return 0;
//}

int main()
{
    int vecVar[TAMVEC] = {0}, tam = 0;
    calculosVector calc;

    ingresarVectorVariable(vecVar, &tam);

    calc.suma = 0;

    sumaYPromedioStruct(vecVar, tam, &calc);

    printf("El promedio de los elementos del vector es: %.2f\n", calc.promedio);
    printf("La suma de los elementos del vector es: %ld\n", calc.suma);


    return 0;
}
