#include "utilidades.h"

///funcion que pasa de el archivo de cabecera de pedido y lo enlaza con los clientes correspondientes

void archivoCabeceraPedido2ListaPedido(nodoCliente* listaCliente, char nombreArch[])
{
    stCabeceraPedido c; ///dato que lee de la cabecera del pedido

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&c, sizeof(stCabeceraPedido), 1, arch) > 0)
        {

            altaPedido(listaCliente, c);
        }
        fclose(arch);
    }
}

/**
ESTA FUNCION SOLO SIRVE PARA EL MOMENTO EN EL QUE SE BAJAN LOS DATOS A LAS LISTAS
CUANDO SE INCICIALIZA EL SISTEMA
NO ES PARA CUANDO EL USUARIO CREE UN NUEVO PEDIDO/PRODUCTO
*/
void altaPedido(nodoCliente* listaCliente, stCabeceraPedido cabecera)
{

    nodoCliente* auxCliente = buscarNodoIdCliente(listaCliente, cabecera.idCliente);

    if(auxCliente)
    {
        auxCliente->listaPedidos = agregarPrincipioListaPedido(auxCliente->listaPedidos, creaNodoPedido(cabecera));
        auxCliente->listaPedidos->costoPedido = 0;
    }

}



///funcion que pasa del archivo de detalle de pedido a la lista de pedidos

void archivoDetalleProducto2ListaProductos(nodoCliente* listaCliente, arbolProducto* productos, char nombreArch[])
{

    stDetallePedidos d;///funcion que almaceno lo que resivo del archivo de detalle
    nodoCliente* auxCliente = NULL;

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&d, sizeof(stDetallePedidos), 1, arch) > 0)
        {
            /// obtengo el cliente en base al id q tiene el detalle
            auxCliente = buscarNodoIdCliente(listaCliente, d.idCliente);

            if(auxCliente)
            {
                altaProducto(auxCliente, d, productos);
            }
        }
        fclose(arch);
    }
}

/**
ESTA FUNCION SOLO SIRVE PARA EL MOMENTO EN EL QUE SE BAJAN LOS DATOS A LAS LISTAS
CUANDO SE INCICIALIZA EL SISTEMA
NO ES PARA CUANDO EL ADMINISTRADOR CREA EL PRODUCTO
*/
void altaProducto(nodoCliente* cliente, stDetallePedidos detalleProducto, arbolProducto* productos)
{
    nodoPedido* auxPedido = buscarNodoIdPedido(cliente->listaPedidos, detalleProducto.idPedido);

    arbolProducto* auxProducto = buscarArbolId(productos, detalleProducto.idProducto);

    if(auxProducto)
    {
        ///agregar a la lista de pedidos el detalle corespondeinte
        auxPedido->listaProducto = agregarPrincipioListaProducto(auxPedido->listaProducto, creaNodoProducto(auxProducto->datoProducto));
    }

}

/**
FUNCION QUE INVOCA A LAS FUNCIONES QUE CARGAN SUS LISTAS DE MANERAS INDEPENDIENTES
RECIBE LA LISTA PRINCIPAL DE CLIENTES Y LOS NOMBRES DE SUS ARCHIVOS DE CABECERA Y DETALLE DE PRODUCTO
*/

nodoCliente* subProgramaCargaSistema(nodoCliente* listaCliente, arbolProducto* productos, char archCliente[], char archCabeceraPedido[], char archDetalleProducto[])
{
    ///funcion que me devuelve la lista de cliente completa con las listas de pedidos inicializadas
    listaCliente = archivoCliente2ListaClientes(listaCliente, archCliente);
    ///funcion que me devuelve la lista de pedidos completa con las listas de productos inicializadas
    archivoCabeceraPedido2ListaPedido(listaCliente, archCabeceraPedido);
    ///funcion que me devuelve la lista de productos completa
    archivoDetalleProducto2ListaProductos(listaCliente, productos, archDetalleProducto);

    return listaCliente;
}



