#ifndef CABECERAPEDIDOS_H_INCLUDED
#define CABECERAPEDIDOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int idCliente;
    char fechaPedido[12];
    int idCabezeraPedido;
    float descuento;
} stCabeceraPedido;


int ultimoIdPedido(char nombreArchivo[]);
void muestraUnaCabezeraPedido(stCabeceraPedido p);





#endif // CABECERAPEDIDOS_H_INCLUDED
