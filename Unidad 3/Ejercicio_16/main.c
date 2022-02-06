#include "funciones.h"

int main()
{
    FILE *arch, *archE, *archD;
    t_producto prod;
    tLista lista;
    char* pathArchD = "depurado.txt";
    char* pathArchE = "errores2.txt";
    char* pathArch = "datos.txt";

    cargarArchivoDatos(pathArch);
    crearLista(&lista);

    arch = fopen(pathArch, "rt");

    while(!feof(arch))
    {
        archAProd(&prod, arch);
        if(buscarClaveInt(&lista, prod.codProd, buscarProd) == 1)
        {
            if( compararDesc(&lista, prod.desc) == 1 )
                actualizarProd(&lista, &prod);
            else
                ponerAlFinal(&lista, &prod, sizeof(t_producto));
        }
        else
            ponerAlFinal(&lista, &prod, sizeof(t_producto));
    }

    fclose(arch);

    archE = fopen(pathArchE, "wt");
    archD = fopen(pathArchD, "wt");

    eliminarDuplicados(&lista, &prod, archE);

    ordenarSelLista(&lista, compararProds);

    while(!listaVacia(&lista))
    {
        sacarPrimeroLista(&lista, &prod, sizeof(t_producto));
        fprintf(archD,"%4d | %s | %02d/%02d/%4d | %02d/%02d/%4d | %02d | %3.2f | %3.2f\n",
                prod.codProd,
                prod.desc,
                prod.fec_compra.d,
                prod.fec_compra.m,
                prod.fec_compra.a,
                prod.fec_venc.d,
                prod.fec_venc.m,
                prod.fec_venc.a,
                prod.cant,
                prod.prec_compra,
                prod.prec_venta
               );
    }

    fclose(archE);
    fclose(archD);

    return 0;
}


void grabarProd(void * vProd, void * param)
{
    FILE * pf = (FILE*)param;
    t_producto * prod = (t_producto*) vProd;
    fprintf(pf, "%d, %s, %s, %d/%d/%d, %d/%d/%d, %d, %f, %f\n",
            prod->codProd,
            prod->desc,
            prod->prov,
            prod->fec_compra.d,
            prod->fec_compra.m,
            prod->fec_compra.a,
            prod->fec_venc.d,
            prod->fec_venc.m,
            prod->fec_venc.a,
            prod->cant,
            prod->prec_compra,
            prod->prec_venta
           );
}
