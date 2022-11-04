#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include "producto.h"
#include <windows.h>
#include "gotoxy.h"

#include "listaCliente.h"///ESTA CONTIENE A TODAS

void archivoCabeceraPedido2ListaPedido(nodoCliente* listaCliente, char nombreArch[]);
void altaPedido(nodoCliente* listaCliente, stCabeceraPedido cabecera);
void archivoDetalleProducto2ListaProductos(nodoCliente* listaCliente, arbolProducto* productos, char nombreArch[]);
void altaProducto(nodoCliente* cliente, stDetallePedidos detalleProducto, arbolProducto* productos);
nodoCliente* subProgramaCargaSistema(nodoCliente* listaCliente, arbolProducto* productos, char archCliente[], char archCabeceraPedido[], char archDetalleProducto[]);

#endif // UTILIDADES_H_INCLUDED
