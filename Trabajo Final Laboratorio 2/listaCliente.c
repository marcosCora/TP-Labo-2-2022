#include "listaCliente.h"

nodoCliente* inicListaCliente()
{
    return NULL;
}

//funcion que crea un nuevo nodoCliente

nodoCliente* creaNodoCliente(stCliente dato)
{
    nodoCliente* nodoNuevo = (nodoCliente*) malloc(sizeof(nodoCliente));
    nodoNuevo->datoCliente = dato;
    nodoNuevo->listaPedidos = inicListaPedido();
    nodoNuevo->siguiente = NULL;

    return nodoNuevo;
}

//Funcion que agrega datos a la lista desde el principio

nodoCliente* agregarPrincipioListaCliente(nodoCliente* lista,nodoCliente * nodoNuevo)
{
    if(lista == NULL)
    {
        lista = nodoNuevo;
    }
    else
    {
        nodoNuevo->siguiente = lista;
        lista = nodoNuevo;
    }

    return lista;
}

///agrego el final de la lista

nodoCliente* agregoFinalListaCliente(nodoCliente* lista, nodoCliente* nuevoNodo)
{
    nodoCliente* ultimo;

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ultimo = buscaUltimoNodoCliente(lista);///almaceno el ultimo nodoCliente en la variable ultimo
        ultimo->siguiente = nuevoNodo;///le asigno el nuevo nodoCliente al siguiente de ultimo
    }

    return lista;
}

///busca ultimo nodo

nodoCliente* buscaUltimoNodoCliente(nodoCliente* lista)
{
    nodoCliente* aux = lista; ///creo una variable auxilar

    if(aux != NULL)
    {
        while(aux->siguiente != NULL) ///recorrre la lista hasta que el siguiente sea NULL
        {
            aux = aux->siguiente;
        }
    }

    return aux;///retorno el ultimo
}


///muestra un nodo

void muestraUnNodoCliente(nodoCliente* listaCliente)
{
    muestraUnCliente(listaCliente->datoCliente);
}


///muestra lista

void muestraListaCliente(nodoCliente* lista)
{
    nodoCliente* aux = lista;

    ///printf("Esta es la lista:\n\n");
    while(aux != NULL)
    {
        muestraUnNodoCliente(aux);
        aux = aux->siguiente;
    }

}


///borrar lista

nodoCliente* borraListaCliente(nodoCliente* lista)
{
    nodoCliente* aux;///creo una variable para ir liberando esa parte de memoria

    while(lista != NULL)
    {
        aux = lista;///le asigno a aux la lista
        lista = lista->siguiente;///lista se asigna el siguiente y pierdo el primer valor
        free(aux);///borro el nodo con la informacion de aux
    }

    return lista;
}

///funcion que elimina el ultimo nodo de una lista
nodoCliente* eliminaUltimoNodoCliente(nodoCliente* lista)
{
    nodoCliente* aux = lista;///creo una variable auxiliar
    nodoCliente* ante;///anterior

    if(lista != NULL)
    {
        while(aux->siguiente != NULL)///recorro hasta el ultimo nodo de la lista
        {
            ante = aux;///le asigno a ante lo que se almacena en aux antes de correr hacia adelante
            aux = aux->siguiente;///me corro de la lista
        }
    }
    ante->siguiente = NULL;
    free(aux);


    return lista;
}


nodoCliente* eliminaPrimerNodoCliente(nodoCliente* lista)
{
    nodoCliente* aux = lista;///creo una lista auxilliar y el asigno la lista recibida

    if(lista != NULL)
    {
        lista = lista->siguiente;///le asgino a lista el siguiente nodo que sera el primero
        free(aux);///elimino el primer nodo
    }

    return lista;///retorno la lista
}

///busca un nodo por numero de id
///retorna el nodo si se encuentra y si no retorna null
nodoCliente* buscarNodoIdCliente(nodoCliente* lista, int id)
{
    nodoCliente* aux = lista;///creo una variable seguidora

    while((aux != NULL) && (aux->datoCliente.idCliente != id))///recorro la lista mientras no finalize o no se encuentre el nodo
    {
        aux = aux->siguiente;
    }

    return aux;///retorno el nodo donde del que se busco o NULL si no se encuentra
}

nodoCliente* borrarNodoIdCliente(nodoCliente* lista, int id)
{
    ///creo dos listas que sirven para recorrer la lista sin perder datos
    nodoCliente* seg;
    nodoCliente* ante;

    if(lista != NULL && lista->datoCliente.idCliente == id)///si la lista no esta vacia y el primer nodoCliente es el buscado se elimina
    {
        lista = eliminaPrimerNodoCliente(lista);
    }
    else
    {
        seg = lista;///le asgino la lista a siguiente
        while((seg != NULL) && seg->datoCliente.idCliente != id)///recorre la lista mientras no sea NULL y no se encuentre el dato
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg != NULL)///si seg no es NULL significa que el dato se encontr
        {
            ante->siguiente = seg->siguiente;///redirreciono los nodos
            free(seg);///elimino el nodoCliente
        }
    }

    return lista;
}

///funcion que devincula un nodo de la lista recibida y lo retorna solo

nodoCliente* desvinculaNodoCliente(nodoCliente** pLista)///recibe un puntero doble a la lista
{
    nodoCliente* aux;///crea un axuliar

    if((*pLista))///mientras a lo que apunta lista tenga datos
    {
        aux  = (*pLista);///le asigno el primer nodo a auxiliar
        (*pLista) = (*pLista)->siguiente;///hago que el primer dato de la lista sea el siguiente del primero recibido
        aux->siguiente = NULL;///el siguiente del primero lo convierto en NULL desvinculando de la lista
    }
    return aux;///retorno el nodo desvinculado
}


















