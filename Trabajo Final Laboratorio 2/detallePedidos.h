#ifndef DETALLEPEDIDOS_H_INCLUDED
#define DETALLEPEDIDOS_H_INCLUDED

#include "cliente.h"
#include "producto.h"

typedef struct
{
    int idPedido;///este id proviene de la lista de pedidos(pedido 1, pedido 2...)
    int idDetallePedido;///autoicrementeal que se agrega en el archivo
    int idProducto;/// viene del arbol
    int idCliente;///de la lista de cliente

}stDetallePedidos;

#endif // DETALLEPEDIDOS_H_INCLUDED
