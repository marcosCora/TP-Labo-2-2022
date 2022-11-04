#ifndef CABECERAPEDIDO_H_INCLUDED
#define CABECERAPEDIDO_H_INCLUDED

#include <time.h>

#include "producto.h"
#include "detallePedido.h"

#define ARCHIVO_CABECERA_PEDIDO "cabeceraPedido.dat"

typedef struct
{
    int idCliente;
    char fechaPedido[20];
    int idCabeceraPedido;
    float descuento;
} stCabeceraPedido;


int ultimoIdPedido(char nombreArchivo[]);
void muestraUnaCabeceraPedido(stCabeceraPedido p);
stCabeceraPedido fechaActual(stCabeceraPedido c);
FILE* abreArchivoCabecera(char nombreArch[]);

#endif // CABECERAPEDIDO_H_INCLUDED
