#include "pila.h"


void inicPila(nodo** pila)
{
    (*pila) = inicLista();
}
int pilaVacia(nodo** pila)
{
    int flag = 0;///devuelve 0 si esta vacia

    if((*pila) != NULL)
    {
        flag = 1;
    }

    return flag;
}

/// invocar a fn de listas q retorne el 1er dato
int tope(nodo** pila)
{
    return buscaPrimerDatoYRetorno((*pila));
}

int desapilar(nodo** pila)
{
    int dato = buscaPrimerDatoYRetorno((*pila));

    (*pila) = eliminaPrimerNodo((*pila));

    return dato;
}

void apilar(nodo** pila, int dato)
{
    ///nodo* nodoNuevo = creaNodo(dato);
    (*pila) = agregarPrincipioLista((*pila), creaNodo(dato));
}

void mostrar(nodo** pila)
{

    printf("\n\nTOPE-----------------------------BASE\n\n");
    muestraLista((*pila));
    printf("\n\nTOPE-----------------------------BASE\n\n");


}

void leer(nodo** pila)
{
    int dato = 0;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    apilar(pila, dato);
}












