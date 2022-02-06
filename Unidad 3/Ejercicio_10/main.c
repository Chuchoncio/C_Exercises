#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

void invertir_pila(tPila* pila);

int main()
{
    long long num1 = 45789652314874152,
              num2 = 78541269854785214;
    int resto = 0;
    int numAlmac1 = 0,
        numAlmac2 = 0,
        numResul = 0,
        carry = 0;

    tPila pilaNum1,
          pilaNum2,
          pilaResul;

    crear_pila(&pilaNum1);
    crear_pila(&pilaNum2);
    crear_pila(&pilaResul);

    while( ((num1 % 10) > 0) && ((num2 % 10) > 0))
    {
        resto = num1 % 10;
        poner_en_pila(&pilaNum1, &resto, sizeof(resto));

        resto = num2 % 10;
        poner_en_pila(&pilaNum2, &resto, sizeof(resto));

        num1 /= 10;
        num2 /= 10;
    }

    invertir_pila(&pilaNum1);
    invertir_pila(&pilaNum2);

    while(!pila_vacia(&pilaNum1) && !pila_vacia(&pilaNum2))
    {
        sacar_de_pila(&pilaNum1, &numAlmac1, sizeof(numAlmac1));
        sacar_de_pila(&pilaNum2, &numAlmac2, sizeof(numAlmac2));

        numResul = numAlmac1 + numAlmac2 + carry;
        if( (numResul / 10) > 0 )
        {
            carry = 1;
            resto = (numResul % 10);

            poner_en_pila(&pilaResul, &resto, sizeof(resto));
        }
        else
        {
            carry = 0;
            poner_en_pila(&pilaResul, &numResul, sizeof(numResul));
        }
    }

    poner_en_pila(&pilaResul, &carry, sizeof(numResul));

    while(!pila_vacia(&pilaResul))
    {
        sacar_de_pila(&pilaResul, &numResul, sizeof(numResul));
        printf("%d", numResul);
    }

    return 0;
}

void invertir_pila(tPila* pila)
{
    int elem, i = 0, antI;
    int vecPila[40];

    while(!pila_vacia(pila))
    {
        sacar_de_pila(pila, &elem, sizeof(elem));
        vecPila[i] = elem;
        i++;
    }

    antI = i;
    i = 0;

    while(i < antI)
    {
        elem = vecPila[i];
        poner_en_pila(pila, &elem, sizeof(elem));
        i++;
    }
}
