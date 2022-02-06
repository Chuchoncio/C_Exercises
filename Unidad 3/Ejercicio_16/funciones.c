#include "funciones.h"

void myMemCpy(void *dest, void *src, size_t n)
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;

   // Copy contents of src[] to dest[]
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}

void mostrarProducto(const t_producto* prod)
{
    printf("%4d | %s | %s | %02d/%02d/%4d | %02d/%02d/%4d | %02d | %3.2f | %3.2f\n",
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

void mostrarDatos(tLista* lista)
{
    t_producto prod;

    printf("CProd Descripcion              Proveedor    Fecha Compra Fecha Venc   Cant Compra   Venta\n");
    printf("===== ======================== ============ ============ ============ ==== ======== =======\n");
    while(!listaVacia(lista))
    {
        sacarPrimeroLista(lista, &prod, sizeof(t_producto));
        mostrarProducto(&prod);
        printf("-------------------------------------------------------------"
               "-------------------------------\n");
    }
}

void archAProd(t_producto* prod, FILE* arch)
{
    char cad[TAM_CAD];
    fgets(cad, TAM_CAD, arch);
    sscanf(cad, "%4d|%[^|\n]|%[^|\n]|%02d/%02d/%04d|%02d/%02d/%04d|%2d|%f|%f\n",
                &prod->codProd,
                prod->desc,
                &prod->fec_compra.d,
                &prod->fec_compra.m,
                &prod->fec_compra.a,
                &prod->fec_venc.d,
                &prod->fec_venc.m,
                &prod->fec_venc.a,
                &prod->cant,
                &prod->prec_compra,
                &prod->prec_venta
                );
}

int compararProds(const void* prod1, const void* prod2)
{
    t_producto* auxProd1 = (t_producto*)prod1;
    t_producto* auxProd2 = (t_producto*)prod2;

    return auxProd1->codProd > auxProd2->codProd ? 1 : auxProd1->codProd < auxProd2->codProd ? -1 : 0;
}

int buscarProd(const int clave, const void* prod)
{
    t_producto* auxProd = (t_producto*)prod;

    return auxProd->codProd == clave ? 1 : 0;
}

int cargarArchivoDatos(char *pathArch)
{
    FILE *arch;
    int i;
    const t_producto vProductos[] =
    {
        {6714,"Sed ante.","35356-932",25,01,2021,1,6,2022,64,699.85,135.37},
        {7310,"Nulla tempus.","60429-743",12,10,2020,4,7,2022,99,648.37,313.57},
        {7537,"Praesent lectus.","52125-275",14,6,2021,2,25,2022,33,735.22,864.76},
        {9567,"Fusce lacus purus.","51079-778",20,10,2020,4,2,2022,47,431.59,429.39},
        {7697,"Maecenas tincidunt.","36987-3409",16,8,2020,1,1,2022,7,883.51,226.73},
        {3640,"Vestibulum sed magna.","51079-462",27,9,2020,1,26,2022,74,846.86,900.55},
        {9576,"Quisque arcu libero.","0430-0530",28,06,2021,2,19,2022,17,384.98,734.22},
        {6641,"In tempor, turpis.","62802-390",24,06,2020,2,27,2022,32,721.12,403.79},
        {7697,"Maecenas tincidunt.","36987-3409",21,9,2020,3,5,2023,10,883.51,226.73},
        {7310,"Nulla","60429-743",12,10,2020,4,7,2022,50,648.37,313.57},
        {1108,"Maecenas rhoncus.","60512-6466",19,07,2020,3,12,2022,43,729.53,369.1},
        {6260,"Nullam orci pede.","54569-5487",18,07,2021,1,24,2022,58,434.06,556.41},
        {6123,"Nulla nisl.","51009-830",2,9,2020,12,25,2021,71,357.77,54.29}
    };

    arch = fopen(pathArch, "wt");

    for(i = 0; i < 11; i++)
    {
        fprintf(arch, "%4d|%-*s|%-*s|%02d/%02d/%4d|%02d/%02d/%4d|%02d|%3.2f|%3.2f\n",
                vProductos[i].codProd,
                22,
                vProductos[i].desc,
                10,
                vProductos[i].prov,
                vProductos[i].fec_compra.d,
                vProductos[i].fec_compra.m,
                vProductos[i].fec_compra.a,
                vProductos[i].fec_venc.d,
                vProductos[i].fec_venc.m,
                vProductos[i].fec_venc.a,
                vProductos[i].cant,
                vProductos[i].prec_compra,
                vProductos[i].prec_venta
                );
    }

    fclose(arch);

    return 0;
}

int compararDesc(tLista * pl, char* desc)
{
    t_producto *prod = (t_producto*)(*pl)->info;
    if( strcmp(prod->desc, desc) )
        return 1;
    else
        return 0;
}

void actualizarProd(tLista * pl, const void * prod)
{
    t_producto * prodA = (t_producto*)prod;

    pl = buscarNodoClave(pl, prodA->codProd, buscarProd);

    t_producto * prodL = (t_producto*)(*pl)->info;

    prodL->cant += prodA->cant;

    /// Fecha compra actu
    prodL->fec_compra.d = prodA->fec_compra.d;
    prodL->fec_compra.m = prodA->fec_compra.m;
    prodL->fec_compra.a = prodA->fec_compra.a;

    /// Fecha venta actu
    prodL->fec_venc.d = prodA->fec_venc.d;
    prodL->fec_venc.m = prodA->fec_venc.m;
    prodL->fec_venc.a = prodA->fec_venc.a;

    if(prodA->prec_compra > prodL->prec_compra)
        prodL->prec_compra = prodA->prec_compra;

     if(prodA->prec_venta > prodL->prec_venta)
        prodL->prec_venta = prodA->prec_venta;
}
