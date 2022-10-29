#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "cliente.h"
#include "arbolProducto.h"
#include "listaCliente.h"
#include "listaPedido.h"
#include "detallePedidos.h"

#include <time.h>

///CONSTANTES
///const int ESC = 27;

#define archCliente "cliente.dat"
///#define archProductos "producto.dat"
#define ARCHIVO_CABECERA_PEDIDO "CabeceraPedido.dat"

void muestraMenu();

nodoCliente* archivoCliente2ListaClientes(nodoCliente* listaCliente, char nombreArch[]);


int main()
{

    arbolProducto* productos = inicArbol();

    productos = subprogramaArchivo2ArbolBalanceado(ARCHIVO_PRODUCTO, productos);

    preorder(productos);

    system("pause");

    char opcion;
    nodoCliente* listaCliente = inicListaCliente();

    /**
    do
    {


        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            printf("Este es el archivo de clientes:\n");
            mostrarArchivoCliente(archCliente);
            break;

        case 50:

            printf("Este es el archivo de productos:\n");
            mostrarArchivoProducto(archProductos);

            break;

        case 51:

            listaCliente = archivoCliente2ListaClientes(listaCliente, ARCHIVO_CLIENTE);
            printf("Lista de clientes\n\n");
            muestraListaCliente(listaCliente);
            break;
        case 52:

            break;
        case 53:

            break;
        case 54:

            break;

        }
        opcion = getch();
    }
    while(opcion != ESC);

*/
    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga que funcion desea realizar\n");
    printf("1- Muestra archivo clientes.\n");
    printf("2- Muestra archivo productos.\n");
    printf("3- Muestra lista clientes\n");
    printf("4- \n");
    printf("5- \n");
    printf("6- \n");
    printf("7- \n");
}

/**

stCabeceraPedido c;

    c.descuento = -1;
    c.idCliente = 2;
    c.idCabezeraPedido = 2;


FILE* arch = fopen(ARCHIVO_CABECERA_PEDIDO, "rb");

    if(arch)
    {
        fwrite(&c, sizeof(stCabeceraPedido), 1, arch);
        fclose(arch);
    }


    while(fread(&c, sizeof(stCabeceraPedido), 1, arch) > 0)
    {
        muestraUnaCabezeraPedido(c);
    }
    */


///funcion que pasa del archivo de clientes
///a una lista de clientes con toda su info
nodoCliente* archivoCliente2ListaClientes(nodoCliente* listaCliente, char nombreArch[])
{
    stCliente c;

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&c, sizeof(stCliente), 1, arch) > 0)
        {
            listaCliente = agregoFinalListaCliente(listaCliente, creaNodoCliente(c));
            listaCliente->listaPedidos = inicListaPedido();///inicializo la lista de pedidos para luego cargarla
            listaCliente->costoTotalPedidos = 0;

            ///listaCliente->listaPedidos = ArchCabeceraPedido2ListaPedido()....id cliente...
            ///dentro de la funcion anterior, vamoa a tener listaCliente->listaPedido->ListaProducto = .......

        }
        fclose(arch);
    }

    return listaCliente;
}




void fechaActual(nodoPedido* pedido)
{
    /// Tiempo actual
    time_t t = time(NULL);

    struct tm tiempoLocal = *localtime(&t);

    /// El lugar en donde se pondrá la fecha y hora formateadas
    char fechaHora[20];

    /// El formato. Mira más en https://en.cppreference.com/w/c/chrono/strftime
    char *formato = "%d/%m/%Y %H:%M:%S";

    /// Intentar formatear
    int bytesEscritos = strftime(fechaHora, sizeof (fechaHora), formato, &tiempoLocal);


    if(bytesEscritos != 0)
    {
        strcpy(pedido->datoPedido.fechaPedido, fechaHora);
    }

}

/** \brief funcion que busca un producto por su id en en el arbolt lo agrega a la lista de productos
 * \param id del producto
 * \return la lista modificada
 *
 */

nodoProducto * arbolToListaProductoId (nodoProducto * listaProd, arbolProducto * arbol, int id)
{
    arbolProducto * aux=buscarArbolId(arbol, id); /// la funcion de busca arbol ya tiene validacion de arbol

    if(aux != NULL)                               /// si es diferente de NULL es porque la encontro
    {
        listaProd = agregarPrincipioListaProducto(listaProd, creaNodoProducto(aux->datoProducto)); /// agretgo el prodcuto a la lista del prodcto
    }

    return listaProd;
}



void altaUnClienteAdminArchivo(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stCliente c;
    int id = ultimoIdCliente(nombreArchivo);
    if(archi)
    {
        system("cls");
        c = cargaUnCliente();           //EN ESTA FUNCION AL IGUAL QUE EN CARGA ARCHIVO CLIENTE TENEMOS QUE HACER TODAS LAS VALIDACIONES
        id++;
        c.idCliente = id;
        c.rol = 1;                        //// pisa el dato de rol para que sea admin
        fwrite(&c, sizeof(stCliente), 1, archi);
        printf("\nRegistro exitoso!\n");
        system("pause");
        fclose(archi);
    }
}


nodoPedido* asignaProductoAPedido(nodoPedido* pedido, arbolProducto* arbolP, int idProducto)///recibe el nodo  pedidos y el arbol de productos
{

    if(pedido)
    {
        pedido->listaProducto = arbolToListaProductoId(pedido->listaProducto, arbolP, idProducto);
    }

    return pedido;
}


///funcion a comprobar

nodoPedido * archivoDetallePedidosToListaPedido(char nombreArchivo[], nodoPedido * listaPedidos, arbolProducto * arbolito){

	arbolProducto * aux = arbolito;
	stDetallePedidos detalle;
	FILE * archi = fopen(nombreArchivo, "rb");

	if(archi){
    	while(fread(&detalle, sizeof(stDetallePedidos), 1, archi) > 0){

        	if(detalle.idPedido == listaPedidos->datoPedido.idCabezeraPedido){
            	arbolProducto * producto = buscarArbolId(producto, detalle.idProducto);
            	listaPedidos = agregarPrincipioListaPedido(listaPedidos, creaNodoPedido(producto->datoProducto));
        	}

    	}
    	fclose(archi);
	}
	return listaPedidos;
}






