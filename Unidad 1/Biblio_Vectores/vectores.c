#include "vectores.h"

void mostrarVector(int* v, int ce)
{
    for(int i = 0 ; i < ce ; i++)
    {
        printf("[%d]", *v);
        v++;
    }
}

void insertarEnVector(int* vec, int elem, int pos, int* ce, int tam)
{
    int *ptr=vec, *ptrPos=vec+(pos-1);

    ptr += *ce;

    /** Si tiene la misma cantidad de elementos que el tamaño del vector
     **     el puntero a vec pasa a una posicion anterior para no irse del vector
     **/
    if(*ce==tam)
        ptr--;

    /** Mientras el puntero a vec no llegue al puntero a pos
     **     se van a ir corriendo los elementos
     **/
    while(ptr!=ptrPos)
    {
        *(ptr) = *(ptr-1);
        ptr--;
    }

    /** Una vez se llega al puntero pos, se procede a insertar el elemento
     **/
    *ptr=elem;

    /** Si la cantidad de elementos no es igual al tamaño del vector
     **     se suma 1 a la cantidad de elementos en el vector
     **/
    if(*ce!=tam)
        (*ce)++;
}

void intercambiar(int* a, int* b)
{
    int aCopia = *a;
    *a = *b;
    *b = aCopia;
}

int* buscarMenor(int* v, int* desde, int* hasta)
{
    int* m = desde;

    for(int* j = desde+1; j <= hasta; j++)
    {
        if(*j < *m)
            m = j;
    }

    return m;
}

void insertarEnVectorYOrdenarAsc(int* vec, int* elem, int* ce, int tam)
{
    int *ptrVec = vec;
    int *ptrElem = elem;

    ptrVec += *ce;

    if(*ce == tam)
        ptrVec--;

    while(*ptrElem < *(ptrVec))
    {
        *(ptrVec+1) = *ptrVec;
        ptrVec--;
        puts("\n");
        mostrarVector(vec, tam);
    }

    *(ptrVec+1)=*ptrElem;

    if(*ce!=tam)
        (*ce)++;
}

void elimPosDeVector(int* vec, int* ce, int pos)
{
    int* ptrVec = vec+(pos-1);

    if(pos > *ce)
        printf("\nNo existe esa posicion, dude!");
    else
    {
        while(*ptrVec)
        {
            *ptrVec = *(ptrVec+1);
            ptrVec++;
        }
        *ce -= 1;
    }
}

void elimPrimApari(int* vec, int elem, int* ce, int tam)
{
    if(*ce > tam)
        return ;

    while(elem != *vec)
        vec++;

    if(elem == *vec)
    {
        while(*vec)
        {
            *vec = *(vec+1);
            vec++;
        }
    }
    else
       return ;
}

void elimTodasApari(int* vec, int elem, unsigned int* ce)
{
    int* ptrVec;
    int* ptrFinVec = vec+(sizeof(vec)-1);
    int* ptrPosActu; /// Puntero que almacena la posicion del vector al mover elementos

    for(ptrVec = vec ; ptrVec < ptrFinVec ; ptrVec++)
    {
        /// Si encuentra el elemento, procede
        if(*ptrVec == elem)
        {
            /* Ternario que verifica que el anterior elemento del vector sea el buscado.
             *     Esto se hace por si hay dos elementos seguidos. Lo que ocurre es
             *     que, al mover el primero de dos seguidos (iguales), el segundo va a
             *     quedar en la posicion del primero, y va a ser ignorado al aumentar
             *     la posicion del vector, cuando el objetivo es eliminarlo tambien.
             */
            *(ptrVec-1) == elem ? ptrVec-- : 0; /* Es increible pero lo solucione con
                                                 *  un ternario <-- no funciona con IF
                                                 */

            ptrPosActu = ptrVec;

            for( ; ptrVec < ptrFinVec ; ptrVec++)
                *ptrVec = *(ptrVec+1);

            ptrVec = ptrPosActu;
            *ce -= 1;
        }
    }
}

//////////////////////////// EJERCICIO 27 ////////////////////////////
char aMinuscula(char c) {return (c) >= 'A' && (c) <= 'Z' ? (c) + ('a' - 'A') :
                (c);}

int determinarPalindromo(char* frase)
{
    // "Ligar es ser agil"
    char* inicFra = frase;
    char* finFra = frase +(strlen(frase)-1);

    if(aMinuscula(*inicFra) != aMinuscula(*finFra))
        return 0;

    /// Verificar cuando haya espacio en cada posicion y en la otra no
    while((aMinuscula(*inicFra) == aMinuscula(*finFra)) && inicFra < finFra)
    {
        inicFra++;
        finFra--;

        if(*inicFra == ',' || *inicFra == ' ')
            inicFra++;

        if(*finFra == ',' || *finFra == ' ')
            finFra--;
    }

    if(inicFra > finFra)
        return 1;
    else
        return 0;
}
//////////////////////////// EJERCICIO 27 ////////////////////////////

//////////////////////////// EJERCICIO 28 ////////////////////////////
/**
    Devuelve el valor numerico de una cadena de caracteres.
    Suponiendo que los valores de las letras sea:

    a = 0
    b = 1
    c = 2
    etc...

    La palabra "cuchame" tiene valor: 2 + 20 + 2 + 7 + 0 + 12 + 4 = 47
  */

int buscarLetra(char letra, char* cad)
{
    int pos = 0;

    while(tolower(letra) != *cad && *cad)
    {
        cad++;
        pos++;
    }

    return pos;
}

int valorNumericoCadena(char* cad)
{
    char abecedario[26] = {"abcdefghijklmnopqrstuvwxyz"};
    int valCadena = 0;

    while(*cad)
    {
        valCadena += buscarLetra(*cad, abecedario);
        cad++;
    }

    return valCadena;
}

//////////////////////////// EJERCICIO 28 ////////////////////////////
