#include "colaEstatica.h"

#define MINIMO(X, Y) ((X)<=(Y)? (X):(Y))

void crearCola(tCola *p)
{
    p->pri = TAM_COLA - 70; // Tanto el primer como el ultimo elemento
    p->ult = TAM_COLA - 70; // comienzan desde un cuarto del total del
    p->tamDisp = TAM_COLA;  // vector
}

int colaLlena(const tCola *p, unsigned tamInfo)
{
    return p->tamDisp <= tamInfo + sizeof(unsigned); // Verifica si existe tamaño para un elemento mas
}

int ponerEnCola(tCola *p, const void * info, unsigned tamInfo)
{
    unsigned ini, fin;

    if(p->tamDisp < sizeof(unsigned) + tamInfo) // Verifica si esta llena la cola
        return 0;

    p->tamDisp -= sizeof(unsigned) + tamInfo;

    /// Copiado de tamaño de la informacion con particion ///

    if( (ini = MINIMO(sizeof(tamInfo),TAM_COLA - p->ult)) != 0)
        memcpy(p->cola + p->ult, &tamInfo, ini);

    if( (fin = sizeof(tamInfo), ini) != 0)
        memcpy(p->cola, ((char*)&tamInfo) + ini, fin);

    /// El puntero al ultimo elemento avanza ini posiciones o
    ///     se queda en fin

    p->ult = fin ? fin : p->ult + ini;

    /// Copiado de la informacion con particion ///

    if( (ini = MINIMO(tamInfo, TAM_COLA - p->tamDisp)) != 0 )
       memcpy(p->cola + p->ult, info, ini);

    if( (fin = tamInfo - ini) != 0)
        memcpy(p->cola, ((char*)info) + ini, fin);

    p->ult = fin ? fin : p->ult + ini;

    return 1;

}

int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo)
{
    unsigned tamInfoCola, ini, fin, pos = p->pri;

    if(p->tamDisp == TAM_COLA)
        return 0;

    if( (ini = MINIMO(sizeof(unsigned), TAM_COLA - pos)) != 0)
        memcpy(&tamInfoCola, p->cola + pos, ini);
    if( (fin = sizeof(unsigned) - ini) != 0)
        memcpy(((char *)&tamInfoCola) + ini, p->cola, fin);

    pos = fin ? fin : pos + ini;
    tamInfoCola = MINIMO(tamInfoCola, tamInfo);

    if( (ini = MINIMO(tamInfoCola, TAM_COLA - pos)) != 0)
        memcpy(info, p->cola + pos, ini);
    if( (fin = tamInfoCola - ini) != 0)
        memcpy(((char*)info) + ini, p->cola, fin);

    return 1;
}


int colaVacia(const tCola *p)
{
    return p->tamDisp == TAM_COLA;
}

int sacarDeCola(tCola *p, void *info, unsigned tamInfo)
{
    unsigned tam, ini, fin;

    if(p->tamDisp == TAM_COLA)
        return 0;

    if( (ini = MINIMO(sizeof(unsigned), TAM_COLA - p->pri)) != 0)
        memcpy(&tam, p->cola + p->pri, ini);
    if( (fin = sizeof(unsigned) - ini) != 0)
        memcpy(((char *)&tam) + ini, p->cola, fin);

    p->pri = fin ? fin : p->pri + ini;
    p->tamDisp += sizeof(unsigned) + tam;
    tam = MINIMO(tam, tamInfo);

    if( (ini = MINIMO(tam, TAM_COLA - p->pri)) != 0)
        memcpy(info, p->cola + p->pri, ini);
    if( (fin = tamInfo - ini) != 0)
        memcpy(((char *)info) + ini, p->cola, fin);

    p->pri = fin ? fin : p->pri + ini;

    return 1;
}

void vaciarCola(tCola *p)
{
    p->ult = p->pri;
    p->tamDisp = TAM_COLA;
}
