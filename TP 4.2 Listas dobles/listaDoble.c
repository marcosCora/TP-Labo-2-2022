#include "listaDoble.h"

nodoDoble* inicListaDoble()
{
    return NULL;
}

nodoDoble* creaNodoDoble(stProducto dato)
{
    nodoDoble* nuevoNodo = (nodoDoble*) malloc(sizeof(nodoDoble));
    nuevoNodo->dato = dato; ///le asigno el dato al nodo nuevo
    nuevoNodo->sig = NULL; ///convierto en NULL el campo siguiente y anterior
    nuevoNodo->ante = NULL;

    return nuevoNodo;
}

nodoDoble* agregarPrincipioListaDoble(nodoDoble* lista,nodoDoble * nodoNuevo)
{

    if(lista == NULL)
    {
        lista = nodoNuevo;///si la lista esta vacia le asigna el nuevo nodo a la lista
    }
    else
    {
        lista->ante = nodoNuevo; ///anterior de lista almacena la direccion del nodo nuevo
        nodoNuevo->sig = lista; ///el siguiente del nodo nuevo almacena la direccion del viejo primer nodo de la lista
        nodoNuevo->ante = NULL; ///el anteror del nuevo principio de la lista apunta a NULL

        lista = nodoNuevo; ///le asigno a la lista la nueva lista con el nodo neuvo
    }

    return nodoNuevo;
}

void muestraUnNodoDoble(nodoDoble* lista)
{
    muestraUnProducto(lista->dato);
}

void muestraListaDoble(nodoDoble* lista)
{
    nodoDoble* aux = lista;

    while(aux != NULL)
    {
        muestraUnNodoDoble(aux);
        aux = aux->sig;
    }
}


///funcion que busca el ultimo nodo en una lista doble

nodoDoble* buscaUltimoNodoDoble(nodoDoble* lista)
{
    nodoDoble* aux = lista;

    while(aux->sig != NULL)///recorro la lista mientras que el dato siquiente no sea NULL
    {
        aux = aux->sig;
    }

    return aux;
}

nodoDoble* agregoFinalListaDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nodoDoble* ultimo;

    if(lista == NULL)
    {
        lista = nuevoNodo;///si la lista es NULL el nuevo nodo es el primero de la lista
    }
    else
    {
        ultimo = buscaUltimoNodoDoble(lista);///retorna el ultimo
        ultimo->sig = nuevoNodo;
        nuevoNodo->ante = ultimo;
        nuevoNodo->sig = NULL;
    }

    return lista;
}

///funcion que elimina toda la lista doble

nodoDoble* borraListaDoble(nodoDoble* lista)
{
    nodoDoble* aux;

    while(lista !=  NULL)
    {
        aux = lista;
        lista = lista->sig;
        free((aux));
    }

    return lista;
}

///funcion que elimina el ultimo nodo de la lista

nodoDoble* eliminaUltimoNodoDoble(nodoDoble* lista)
{

    nodoDoble* aux = lista;
    nodoDoble* ante;

    if(lista)
    {
        while(aux->sig != NULL)
        {
            ante = aux;
            aux = aux->sig;
        }
    }

    ante->sig = NULL;
    free(aux);


    return lista;
}

///funcion que elimina el primer nodo de la lista

nodoDoble* eliminaPrimerNodoDoble(nodoDoble* lista)
{
    nodoDoble* aux = lista;

    if(lista != NULL)
    {
        lista = lista->sig;
        lista->ante = NULL;
        free(aux);
    }
    return lista;
}

///funcion que busca un nodo por id

nodoDoble* buscarNodoDobleId(nodoDoble* lista, int id)
{
    nodoDoble* aux = lista;

    while(aux != NULL && aux->dato.idProducto != id)
    {
        aux = aux->sig;
    }

    return aux;
}

///borra un nodo por id

nodoDoble* borrarNodoId(nodoDoble* lista, int id)
{
    nodoDoble* ante;
    nodoDoble* seg;
    nodoDoble* aux;

    aux = buscarNodoDobleId(lista, id);///llama  a la funcion que busca el nodo por id pedido

    if(aux != NULL)///si el nodo se encentrs es distinto de null
    {

        if(aux->ante == NULL)///si el nodo a borrar es el primero
        {
            lista = eliminaPrimerNodoDoble(lista);///elimina el primer nodo de la lista
        }
        else
        {
            ante = aux->ante;///asigno el anterior del nodo buscado a la variable ante
            seg = aux->sig;///asigno el siguiente del nodo buscado a la variable siguiente

            ante->sig = seg;///anterior siguiente es igual a seg que es el proximo del nodo que se elimina
            if(seg)///si seg no es null porq no es el ultimo nodo de la lista
            {
                seg->ante = ante;///aigna siguiente anterior a ante
                free(aux);
            }
            ///si no entra al if es porq siguiente del nodo a eliminar el NULL por ende ante pasaria a ser el ultimo nodo
        }

    }


    return lista;
}

///funcion que agrega en orden por marca a una lista ordenada

nodoDoble* agregarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nodoDoble* seg;
    nodoDoble* ante;

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmpi(lista->dato.marca, nuevoNodo->dato.marca) > 0)
        {
            lista = agregarPrincipioListaDoble(lista, nuevoNodo);
        }
        else
        {
            ante=lista;
            seg = lista->sig;
            while(seg != NULL && strcmpi(seg->dato.marca, nuevoNodo->dato.marca) < 0)
            {
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevoNodo;
            nuevoNodo->ante = ante;
            nuevoNodo->sig = seg;
            if(seg != NULL)
            {
                seg->ante = nuevoNodo;
            }
        }

    }


    return lista;
}


















