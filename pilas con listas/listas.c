#include "listas.h"

nodo* inicLista()
{
    return NULL;
}

///funcion que crea un nuevo nodo

nodo* creaNodo(int dato)
{
    ///creo en espacio de memoria un lugar para almacenar mi nuevo nodo
    nodo* nodoNuevo = (nodo*) malloc(sizeof(nodo));

    ///le asigno el dato a el nodo nuevo
    nodoNuevo->dato = dato;

    ///marco el siguiente nodo como NULL
    nodoNuevo->sig = NULL;


    return nodoNuevo;
}

///Funcion que agrega datos a la lista desde el principio

nodo* agregarPrincipioLista(nodo* lista,nodo * nodoNuevo)
{
    ///si la lista no tiene nodos asgina el nuevoNodo como primer elemento de la lista
    if(lista == NULL)
    {
        lista = nodoNuevo;
    }
    else
    {
        ///si no al nuevo nodo le carga la direccion de memoria del primer nodo de la lista
        nodoNuevo->sig = lista;

        ///piso lo que almacena lista con el nodoNuevo ya que este contiene las direcciones de los siguientes nodo al
        ///almacenarse en el principio de la lista
        lista = nodoNuevo;
    }

    return lista;
}


///muestra un nodo
/**
void muestraUnNodo(nodo * nodo)
{
    muestraUnProducto(nodo->dato);
}
*/


///muestra lista

void muestraLista(nodo* lista)
{
    nodo* aux = lista;


    while(aux != NULL)
    {
        printf("| %d |", aux->dato);
        aux = aux->sig;
    }

}

///busca ultimo nodo

nodo* buscaUltimoNodo(nodo* lista)
{
    nodo* aux = lista; ///creo una variable auxilar

    if(aux != NULL)
    {
        while(aux->sig != NULL) ///recorrre la lista hasta que el siguiente sea NULL
        {
            aux = aux->sig;
        }
    }

    return aux;///retorno el ultimo
}

///agrego el final de la lista
/// A PROBAR

int* agregoFinalLista(nodo* lista, int* nuevoNodo)
{
    nodo* ultimo;

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ultimo = buscaUltimoNodo(lista);///almaceno el ultimo nodo en la variable ultimo
        ultimo->sig = nuevoNodo;///le asigno el nuevo nodo al siguiente de ultimo
    }

    return lista;
}


///borrar lista

nodo* borraLista(nodo* lista)
{
    int* aux;///creo una variable para ir liberando esa parte de memoria

    while(lista != NULL)
    {
        aux = lista;///le asigno a aux la lista
        lista = lista->sig;///lista se asigna el siguiente y pierdo el primer valor
        free(aux);///borro el nodo con la informacion de aux
    }

    return lista;
}

///funcion que elimina el ultimo nodo de una lista
nodo* eliminaUltimoNodo(nodo* lista)
{
    nodo* aux = lista;///creo una variable auxiliar
    nodo* ante;///anterior

    if(lista != NULL)
    {
        while(aux->sig != NULL)///recorro hasta el ultimo nodo de la lista
        {
            ante = aux;///le asigno a ante lo que se almacena en aux antes de correr hacia adelante
            aux = aux->sig;///me corro de la lista
        }
    }
    ante->sig = NULL;
    free(aux);


    return lista;
}


nodo* eliminaPrimerNodo(nodo* lista)
{
    nodo* aux = lista;///creo una lista auxilliar y el asigno la lista recibida

    if(lista != NULL)
    {
        lista = lista->sig;///le asgino a lista el siguiente nodo que sera el primero
        free(aux);///elimino el primer nodo
    }


    return lista;///retorno la lista
}

///funcion que retorna el primer dato de la lista

int buscaPrimerDatoYRetorno(nodo* lista)
{
    int dato = 0;

    if(lista)
    {
        dato = lista->dato;
    }

    return dato;
}

/**

///busca un nodo por numero de id
///retorna el nodo si se encuentra y si no retorna null
nodo* buscarNodoId(nodo* lista, int id)
{
    nodo* aux = lista;///creo una variable seguidora

    while((aux != NULL) && (aux->dato.idProducto != id))///recorro la lista mientras no finalize o no se encuentre el nodo
    {
        aux = aux->sig;
    }


    return aux;///retorno el nodo donde del que se busco o NULL si no se encuentra
}

nodo* borrarNodoId(nodo* lista, int id)
{
    ///creo dos listas que sirven para recorrer la lista sin perder datos
    nodo* seg;
    nodo* ante;

    if(lista != NULL && lista->dato.idProducto == id)///si la lista no esta vacia y el primer nodo es el buscado se elimina
    {
        lista = eliminaPrimerNodo(lista);
    }
    else
    {
        seg = lista;///le asgino la lista a siguiente
        while((seg != NULL) && seg->dato.idProducto != id)///recorre la lista mientras no sea NULL y no se encuentre el dato
        {
            ante = seg;
            seg = seg->sig;
        }
        if(seg != NULL)///si seg no es NULL significa que el dato se encontr
        {
            ante->sig = seg->sig;///redirreciono los nodos
            free(seg);///elimino el nodo
        }
    }

    return lista;
}


///funcion que agrega en orden a una lista ya ordenada

nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo)
{
    nodo* seg = lista;
    nodo* ante;

    ///si el nuevo nodo debe colocarse al principio se llama a la funcion de agregar el principio
    if((seg != NULL) && (strcmpi(seg->dato.marca, nuevoNodo->dato.marca) > 0))
    {
        lista = agregarPrincipioLista(lista, nuevoNodo);
    }
    else///si no recoore la lista y busca el hueco donde ubicarlo
    {
        while((seg != NULL) && (strcmpi(seg->dato.marca, nuevoNodo->dato.marca) < 0))
        {
            ante = seg;
            seg = seg->sig;

        }
        ante->sig = nuevoNodo;
        nuevoNodo->sig = seg;
    }


    return lista;
}


///funcion que va creando una lista ordenada a medida que es cargada
nodo* crearListaOrdenadaMarca(nodo* lista)
{
    char opcion;
    int p;
    nodo* nuevoNodo;

    nodo* seg;
    nodo* ante;

    while(opcion != ESC)
    {
        p = cargaUnProducto();
        nuevoNodo = creaNodo(p);

        if(lista == NULL)
        {
            lista = agregoFinalLista(lista, nuevoNodo);
        }
        else
        {
            lista = agregarEnOrden(lista, nuevoNodo);
        }

        printf("\nESC para salir/otro para continuar\n\n");
        opcion = getch();

        /*
        if(lista == NULL)
        {
            lista = agregoFinalLista(lista, nuevoNodo);
        }
        else
        {
            seg = lista;
            while((lista != NULL))

        }


    }

    return lista;
}
*/









