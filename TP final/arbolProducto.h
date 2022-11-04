#ifndef ARBOLPRODUCTO_H_INCLUDED
#define ARBOLPRODUCTO_H_INCLUDED

#include "producto.h"

typedef struct _arbol
{
    stProducto datoProducto;
    struct _arbol* izq;
    struct _arbol* der;
}arbolProducto;

arbolProducto * inicArbol ();
arbolProducto * crearNodoArbol (stProducto dato);

void muestraUnNodoArbol (arbolProducto * arbol);
void preorder (arbolProducto * arbol);
void inorder (arbolProducto * arbol);
void posorder(arbolProducto * arbol);

arbolProducto * insertarArbolId (arbolProducto * arbol, arbolProducto * nuevo);
arbolProducto * buscarArbolId (arbolProducto * arbol, int id);
arbolProducto * subprogramaArchivo2ArbolBalanceado(char nombreArchivo[], arbolProducto * arbol);

///FUNCION PARA LA AGREGAR EN UN ARBOL DESDE UN ARRAY Y QUE ESTE EQUILIBRADO
arbolProducto* array2Arbol(stProducto p[], int i, int v);

#endif // ARBOLPRODUCTO_H_INCLUDED
