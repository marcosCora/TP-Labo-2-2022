#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include "listaPedido.h"
#include "cliente.h"

typedef struct _nodoCliente
{
    stCliente datoCliente;
    struct _nodoCliente * siguiente;
    nodoPedido* listaPedidos;
    float costoTotalPedidos;

}nodoCliente;

nodoCliente* inicListaCliente();
nodoCliente* creaNodoCliente(stCliente dato);
nodoCliente* agregarPrincipioListaCliente(nodoCliente* lista,nodoCliente * nodoNuevo);
nodoCliente* agregoFinalListaCliente(nodoCliente* lista, nodoCliente* nuevoNodo);
nodoCliente* buscaUltimoNodoCliente(nodoCliente* lista);
void muestraUnNodoCliente(nodoCliente* listaCliente);
void muestraListaCliente(nodoCliente* lista);
nodoCliente* borraListaCliente(nodoCliente* lista);///modificar
nodoCliente* eliminaUltimoNodoCliente(nodoCliente* lista);
nodoCliente* eliminaPrimerNodoCliente(nodoCliente* lista);
nodoCliente* buscarNodoIdCliente(nodoCliente* lista, int id);
nodoCliente* borrarNodoIdCliente(nodoCliente* lista, int id);
nodoCliente* desvinculaNodoCliente(nodoCliente** pLista);

int buscaRolEnListaCliente(nodoCliente* lista, char userName[20]);

///manejo de archivo
nodoCliente* archivoCliente2ListaClientes(nodoCliente* listaCliente, char nombreArch[]);



#endif // LISTACLIENTE_H_INCLUDED
