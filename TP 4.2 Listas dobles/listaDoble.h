#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "producto.h"

typedef struct _nodo
{
    stProducto dato;
    struct _nodo* sig;
    struct _nodo* ante;

}nodoDoble;


///FUNCIONES PRIMITIVAS

nodoDoble* inicListaDoble();
nodoDoble* creaNodoDoble(stProducto dato);
nodoDoble* agregarPrincipioListaDoble(nodoDoble* lista,nodoDoble * nodoNuevo);
nodoDoble* buscaUltimoNodoDoble(nodoDoble* lista);
nodoDoble* agregoFinalListaDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borraListaDoble(nodoDoble* lista);
nodoDoble* eliminaUltimoNodoDoble(nodoDoble* lista);
nodoDoble* eliminaPrimerNodoDoble(nodoDoble* lista);


void muestraListaDoble(nodoDoble* lista);

///FUNCIONES DEPENDEINTES DE LA ESTRUCTURA
void muestraUnNodoDoble(nodoDoble* lista);

nodoDoble* buscarNodoDobleId(nodoDoble* lista, int id);
nodoDoble* borrarNodoId(nodoDoble* lista, int id);
nodoDoble* agregarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo);

///nodoDoble* crearListaOrdenadaMarca(nodoDoble* lista);







#endif // LISTADOBLE_H_INCLUDED
