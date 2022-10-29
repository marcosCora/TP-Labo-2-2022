#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "producto.h"

typedef struct _nodo
{
    stProducto datoProducto;
    struct _nodo *siguiente;

}nodoProducto;


///FUNCIONES PRIMITIVAS
///FUNCIONES QUE PIDE DEL TP

nodoProducto* inicListaProducto();
nodoProducto* creaNodoProducto(stProducto datoProducto);
nodoProducto* agregarPrincipioListaProducto(nodoProducto* lista,nodoProducto * nodoNuevo);
nodoProducto* agregoFinalListaProducto(nodoProducto* lista, nodoProducto* nuevoNodo);
nodoProducto* agregarEnOrdenListaXNombreProducto(nodoProducto* lista, nodoProducto* nuevoNodo);
nodoProducto* buscaUltimoNodoProducto(nodoProducto* lista);
void muestraListaProducto(nodoProducto* lista);
void muestraUnNodoProducto(nodoProducto * nodoProducto);


nodoProducto* borrarNodoIdProducto(nodoProducto* lista, int id);
nodoProducto* borraListaProducto(nodoProducto* lista);
nodoProducto* eliminaUltimoNodoProducto(nodoProducto* lista);
nodoProducto* eliminaPrimerNodoProducto(nodoProducto* lista);
nodoProducto* desvinculaNodoProducto(nodoProducto** pLista);
nodoProducto* buscarNodoProducto(nodoProducto* lista, int id);
nodoProducto* crearListaOrdenadaXNombreProducto(nodoProducto* lista);



#endif // LISTA_H_INCLUDED
