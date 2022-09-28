#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "producto.h"

typedef struct _nodo
{
    stProducto dato;
    struct _nodo *sig;
}nodo;


///FUNCIONES PRIMITIVAS

nodo* inicLista();
nodo* creaNodo(stProducto dato);
nodo* agregarPrincipioLista(nodo* lista,nodo * nodoNuevo);
nodo* buscaUltimoNodo(nodo* lista);
nodo* agregoFinalLista(nodo* lista, nodo* nuevoNodo);
nodo* borraLista(nodo* lista);
nodo* eliminaUltimoNodo(nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);

nodo* desvinculaNodo(nodo** pLista);

void muestraLista(nodo* lista);

///FUNCIONES DEPENDEINTES DE LA ESTRUCTURA
void muestraUnNodo(nodo * nodo);

nodo* buscarNodo(nodo* lista, int id);
nodo* borrarNodoId(nodo* lista, int id);
nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* crearListaOrdenadaMarca(nodo* lista);

///FUNCIONES LISTAS SIMPLES RECURSIVAS

/**
6. Insertar un nodo en una lista en forma recursiva
(manteniendo el orden de forma creciente)
*/

void muestraListaRecursiva(nodo* lista);
nodo* borraNodoRecursivoID(nodo* lista, int id);

nodo* agregarEnOrdenRecursivo(nodo* lista, nodo* nuevoNodo);







#endif // LISTAS_H_INCLUDED
