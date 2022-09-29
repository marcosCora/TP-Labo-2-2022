#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo *sig;
}nodo;


///FUNCIONES PRIMITIVAS

nodo* inicLista();
nodo* creaNodo(int dato);
nodo* agregarPrincipioLista(nodo* lista,nodo * nodoNuevo);
nodo* buscaUltimoNodo(nodo* lista);
int* agregoFinalLista(nodo* lista, int* nuevoNodo);
nodo* borraLista(nodo* lista);
nodo* eliminaUltimoNodo(nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);

void muestraLista(nodo* lista);

int buscaPrimerDatoYRetorno(nodo* lista);

///FUNCIONES DEPENDEINTES DE LA ESTRUCTURA
void muestraUnNodo(nodo * nodo);

/**
nodo* buscarNodo(nodo* lista, int id);
nodo* borrarNodoId(nodo* lista, int id);
nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo);
nodo* crearListaOrdenadaMarca(nodo* lista);
*/



#endif // LISTAS_H_INCLUDED
