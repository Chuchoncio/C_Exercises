#include "main.h"

int main()
{
    tProducto p7, p1, p2, p3, p4, p5, pe;
    tLista lista;

    crearLista(&lista);

    if(listaVacia(&lista))
    {
        printf("\nLa lista se encuentra vacia \n\n");
    }

    if(listaLlena(&lista, sizeof(tProducto)))
    {
        printf("\nLa lista se encuentra llena \n\n");
    }

    crearProducto(&p1, 1, "Producto 1", 111.11, 11);
    insertarAlComienzo(&lista, &p1, sizeof(tProducto));
    crearProducto(&p5, 5, "Producto 5", 555.55, 40);
    insertarAlComienzo(&lista, &p5, sizeof(tProducto));
    crearProducto(&p2, 2, "Producto 2", 22.22, 22);
    insertarAlComienzo(&lista, &p2, sizeof(tProducto));

    crearProducto(&p7, 7, "Producto 7", 0.701, 74);
    insertarAlComienzo(&lista, &p7, sizeof(tProducto));

    printf("\n\n#### Mostrar lista de Derecha a Izquierda\n\n");
    mostrarDerAIzq(&lista, mostrarProducto);
    printf("\n\n#### Mostrar lista de Izquierda a Derecha\n\n");
    mostrarDeIzqADer(&lista, mostrarProducto);

    printf("\n\n#### Lista ordenada: \n\n");
    ordenarLista(&lista, compararProductoID);
    mostrarDeIzqADer(&lista, mostrarProducto);

    crearProducto(&p4, 4, "Producto 4", 44.0, 70);
    insertarEnOrden(&lista, &p4, sizeof(tProducto), compararProductoID, acumularProducto);
    crearProducto(&p3, 3, "Producto 3", 33.2, 550);
    insertarEnOrden(&lista, &p3, sizeof(tProducto), compararProductoID, acumularProducto);
    crearProducto(&p4, 4, "Producto 4", 44.0, 30);
    insertarEnOrden(&lista, &p4, sizeof(tProducto), compararProductoID, acumularProducto);

    printf("\n\n#### Lista luego de la insercion en orden\n\n");
    mostrarDeIzqADer(&lista, mostrarProducto);

    pe.id_producto = 2;
    eliminarPorClave(&lista, &pe, sizeof(tProducto), compararProductoID);
    printf("\n\n#### Datos del producto eliminado de la lista \n\n");
    mostrarProducto(NULL);
    mostrarProducto(&pe);

    printf("\n\n#### Lista luego de la eliminacion del producto\n\n");

    mostrarDeIzqADer(&lista, mostrarProducto);

    vaciarLista(&lista);

    printf("\n FIN \n");

    return 0;
}
