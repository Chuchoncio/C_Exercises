#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAM_CAD 100

typedef struct
{
    int d,
        m,
        a;
} t_fecha;

typedef struct
{
    int codProd;
    char desc[43];
    char prov[11];
    t_fecha fec_compra,
            fec_venc;
    int cant;
    float prec_compra,
          prec_venta;
} t_producto;

int cargarArchivoDatos(char *pathArch);
void archAProd(t_producto* prod, FILE* arch);
int compararProds(const void* prod1, const void* prod2);
void mostrarProducto(const t_producto* prod);
void mostrarDatos(tLista* lista);
void myMemCpy(void *dest, void *src, size_t n);
int buscarProd(const int clave, const void* prod);
int compararDesc(tLista * pl, char* desc);
void actualizarProd(tLista * pl, const void * prod);

#endif // FUNCIONES_H_INCLUDED
