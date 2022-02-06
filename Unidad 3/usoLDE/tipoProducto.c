#include "tipoProducto.h"

void crearProducto(tProducto *d, long id_producto, char *descripcion,
                   float precioUnitario, int cantidad)
{
    d->id_producto = id_producto;
    strcpy(d->descripcion, descripcion);
    d->precioUnitario = precioUnitario;
    d->cantidad = cantidad;
}

void mostrarProducto(const void *dv)
{
    tProducto *d = (tProducto *)dv;
    if(d == NULL)
    {
        printf("ID_PRODUCTO DESCRIPCION                   PRECIO_UNITARIO CANTIDAD\n");
        printf("----------- ----------------------------- --------------- --------\n");
    }
    else
    {
        printf("%011ld %-*.*s %06.2f          %03d\n",   d->id_producto,
                                                       (int)sizeof(d->descripcion)-1,
                                                       (int)sizeof(d->descripcion)-1,
                                                       d->descripcion,
                                                       d->precioUnitario,
                                                       d->cantidad);
    }
}

int compararProductoID(const void *p1v, const void *p2v)
{
    tProducto *p1 = (tProducto *) p1v;
    tProducto *p2 = (tProducto *) p2v;
    return p1->id_producto - p2->id_producto;
}

int acumularProducto(void **p1v, unsigned *tp1, const void *p2v, unsigned tp2)
{
    tProducto **p1 = (tProducto **) p1v;
    tProducto *p2 = (tProducto *) p2v;
    (*p1)->cantidad += p2->cantidad;

    return 1;
}
